#!/usr/bin/env bash
# studyos.sh - All-in-one terminal productivity OS
# Version: 1.0.1 (Patched)
# License: MIT
# Description: A modular TUI (Terminal User Interface) productivity tool written in pure Bash.

# ============================================================================
# SEKCJA 1: GLOBALS & CONSTANTS (linie 1-100)
# ============================================================================
set -euo pipefail  # Strict mode

# === PATHS ===
readonly SCRIPT_NAME="StudyOS"
readonly VERSION="1.0.1"
readonly DATA_DIR="${HOME}/.studyos"
readonly CONFIG_FILE="${DATA_DIR}/config.conf"
readonly NOTES_FILE="${DATA_DIR}/notes.txt"
readonly TODO_FILE="${DATA_DIR}/todo.txt"
readonly FLASH_FILE="${DATA_DIR}/flashcards.txt"
readonly POMO_LOG="${DATA_DIR}/pomodoro.log"
readonly HABITS_FILE="${DATA_DIR}/habits.txt"
readonly CALENDAR_FILE="${DATA_DIR}/calendar.txt"
readonly STATS_FILE="${DATA_DIR}/stats.log"
readonly CACHE_DIR="${DATA_DIR}/cache"
readonly QUOTE_CACHE="${CACHE_DIR}/quotes.cache"
readonly WEATHER_CACHE="${CACHE_DIR}/weather.cache"

# === SCREEN STATE ===
SCREEN_WIDTH=0
SCREEN_HEIGHT=0
CURRENT_VIEW="dashboard"
NEEDS_REDRAW=true
MENU_SELECTED=0
INPUT_MODE=false
CURRENT_INPUT_PROMPT=""
# Nie używamy już TEMP_INPUT/CURRENT_ACTION - input jest synchroniczny

# === THEME DEFAULTS ===
THEME_COLOR=2              # Green
THEME_BORDER="single"
ANIMATION_ENABLED=true
ANIMATION_SPEED=0.02

# === APP STATE ===
declare -A CONFIG          # Associative array dla config
ONLINE_MODE=false
POMODORO_RUNNING=false
POMODORO_PID=""
POMODORO_START_TIME=0
POMODORO_DURATION_SECS=0
LAST_REFRESH=0
REFRESH_INTERVAL=60

# === TEMPORARY STATE (dla wiadomości) ===
ERROR_MESSAGE=""
SUCCESS_MESSAGE=""

# ============================================================================
# SEKCJA 2: INITIALIZATION & SETUP (linie 101-300)
# ============================================================================

# === INITIALIZE APPLICATION ===
init_app() {
    # Check terminal capabilities
    check_terminal || exit 1
    
    # Create directory structure
    create_directories
    
    # Generate default files if missing
    generate_default_files
    
    # Load configuration
    load_config
    
    # Check dependencies
    check_dependencies
    
    # Check internet
    check_internet_connection
    
    # Setup signal handlers
    setup_traps
    
    # Initialize screen
    init_screen
    
    # First time setup wizard
    if [[ ! -f "${DATA_DIR}/.initialized" ]]; then
        first_time_setup
    fi
    
    # WAŻNE: Jawnie zwracamy sukces, aby set -e nie zamknęło skryptu
    return 0
}

# === CHECK TERMINAL ===
check_terminal() {
    if ! command -v tput &>/dev/null; then
        echo "ERROR: 'tput' not found. Install ncurses-utils." >&2
        return 1
    fi
    
    local cols lines
    cols=$(tput cols)
    lines=$(tput lines)
    
    if (( cols < 80 || lines < 24 )); then
        echo "ERROR: Terminal too small. Minimum 80x24, got ${cols}x${lines}" >&2
        return 1
    fi
    
    if (( $(tput colors) < 8 )); then
        echo "WARNING: Limited color support detected" >&2
        THEME_COLOR=7  # White fallback
    fi
    
    return 0
}

# === CREATE DIRECTORIES ===
create_directories() {
    mkdir -p "$DATA_DIR" \
             "$CACHE_DIR" \
             "${DATA_DIR}/backups" \
             "${DATA_DIR}/exports"
}

# === GENERATE DEFAULT FILES ===
generate_default_files() {
    # Config file
    if [[ ! -f "$CONFIG_FILE" ]]; then
        cat > "$CONFIG_FILE" << 'EOF'
# StudyOS Configuration
THEME_COLOR=2
THEME_BORDER=single
ANIMATION_ENABLED=true
ANIMATION_SPEED=0.02
AUTO_SAVE=true
CONFIRM_DELETE=true
POMODORO_DURATION=25
POMODORO_BREAK=5
POMODORO_LONG_BREAK=15
WEATHER_CITY=Warsaw
WEATHER_UNITS=metric
QUOTE_SOURCE=zenquotes
KEY_UP=k
KEY_DOWN=j
KEY_QUIT=q
KEY_HELP=?
EOF
    fi
    
    # Notes file
    if [[ ! -f "$NOTES_FILE" ]]; then
        cat > "$NOTES_FILE" << 'EOF'
# StudyOS Notes Database
# Format: ID|timestamp|title|content|tags
EOF
    fi
    
    # TODO file
    if [[ ! -f "$TODO_FILE" ]]; then
        cat > "$TODO_FILE" << 'EOF'
# StudyOS TODO Database
# Format: ID|created|due|priority|status|title|project|tags
EOF
    fi
    
    if [[ ! -f "$FLASH_FILE" ]]; then
        cat > "$FLASH_FILE" << 'EOF'
# StudyOS Flashcards Database
# Format: ID|deck|question|answer|easiness|interval|next_review|times_reviewed
EOF
    fi
    
    if [[ ! -f "$POMO_LOG" ]]; then
        cat > "$POMO_LOG" << 'EOF'
# StudyOS Pomodoro Log
# Format: timestamp|duration_minutes|task|completed(yes/no)|interruptions
EOF
    fi
    
    if [[ ! -f "$HABITS_FILE" ]]; then
        cat > "$HABITS_FILE" << 'EOF'
# StudyOS Habits Tracker
# Format: ID|name|description|streak|last_done|created|target_frequency
EOF
    fi
    
    if [[ ! -f "$CALENDAR_FILE" ]]; then
        cat > "$CALENDAR_FILE" << 'EOF'
# StudyOS Calendar
# Format: ID|date|time|title|type|reminder_minutes|status
EOF
    fi
    
    if [[ ! -f "$STATS_FILE" ]]; then
        cat > "$STATS_FILE" << 'EOF'
# StudyOS Statistics Log
# Format: timestamp|module|action|duration_seconds|metadata
EOF
    fi
}

# === LOAD CONFIG ===
load_config() {
    [[ ! -f "$CONFIG_FILE" ]] && return
    
    while IFS='=' read -r key value; do
        [[ "$key" =~ ^[[:space:]]*# ]] && continue
        [[ -z "$key" ]] && continue
        
        key=$(echo "$key" | xargs)
        value=$(echo "$value" | xargs)
        
        CONFIG["$key"]="$value"
    done < "$CONFIG_FILE"
    
    THEME_COLOR="${CONFIG[THEME_COLOR]:-2}"
    THEME_BORDER="${CONFIG[THEME_BORDER]:-single}"
    ANIMATION_ENABLED="${CONFIG[ANIMATION_ENABLED]:-true}"
    ANIMATION_SPEED="${CONFIG[ANIMATION_SPEED]:-0.02}"
}

# === CHECK DEPENDENCIES ===
check_dependencies() {
    local missing=()
    
    if ! command -v bash &>/dev/null; then missing+=("bash"); fi
    if ! command -v tput &>/dev/null; then missing+=("tput"); fi
    if ! command -v date &>/dev/null; then missing+=("date"); fi
    if ! command -v sed &>/dev/null; then missing+=("sed"); fi
    if ! command -v awk &>/dev/null; then missing+=("awk"); fi
    
    if ! command -v curl &>/dev/null; then
        ONLINE_MODE=false
        log_message "WARNING" "curl not found - online features disabled"
    fi
    
    if ! command -v bc &>/dev/null; then
        log_message "WARNING" "bc not found - calculator disabled"
    fi
    
    if ! command -v fold &>/dev/null; then
        log_message "WARNING" "fold not found - text wrapping limited"
    fi
    
    if (( ${#missing[@]} > 0 )); then
        echo "ERROR: Missing required dependencies: ${missing[*]}" >&2
        exit 1
    fi
}

# === CHECK INTERNET ===
check_internet_connection() {
    if command -v curl &>/dev/null; then
        if curl -Ls --max-time 3 "https://www.google.com" &>/dev/null; then
            ONLINE_MODE=true
        else
            ONLINE_MODE=false
        fi
    else
        ONLINE_MODE=false
    fi
}

# === SETUP TRAPS ===
setup_traps() {
    trap 'handle_resize' SIGWINCH
    trap 'cleanup_and_exit' EXIT INT TERM
    trap 'NEEDS_REDRAW=true' USR1
}

# === HANDLE RESIZE ===
handle_resize() {
    update_screen_size
    NEEDS_REDRAW=true
}

# === CLEANUP ===
cleanup_and_exit() {
    if [[ -n "$POMODORO_PID" ]]; then
        kill "$POMODORO_PID" 2>/dev/null || true
    fi
    
    rm -f "${DATA_DIR}"/*.lock 2>/dev/null || true
    rm -f /tmp/studyos_editor.* 2>/dev/null || true
    
    tput clear
    tput cnorm
    tput sgr0
    
    if (( SCREEN_HEIGHT > 0 )); then
        tput cup "$((SCREEN_HEIGHT - 1))" 0
    fi
    
    trap - EXIT
    trap - INT
    trap - TERM
    
    echo "Thanks for using StudyOS!"
    exit 0
}

# === FIRST TIME SETUP WIZARD ===
first_time_setup() {
    clear_screen
    
    draw_welcome_screen
    
    echo "StudyOS First Run Setup"
    echo "======================="
    
    CONFIG["USER_NAME"]=$(get_user_input "Enter your name (optional)")
    CONFIG["POMODORO_DURATION"]=$(get_user_input "Default Pomodoro duration (minutes) [25]" 25)
    CONFIG["WEATHER_CITY"]=$(get_user_input "Your city for weather [Warsaw]" Warsaw)
    
    echo ""
    echo "Choose color scheme:"
    echo "1) Green (Matrix style)"
    echo "2) Blue (Ocean)"
    echo "3) Yellow (Amber)"
    echo "4) White (Classic)"
    local theme_choice=$(get_user_input "Choice [1]" 1)
    
    case "$theme_choice" in
        1) CONFIG["THEME_COLOR"]=2 ;;
        2) CONFIG["THEME_COLOR"]=4 ;;
        3) CONFIG["THEME_COLOR"]=3 ;;
        4) CONFIG["THEME_COLOR"]=7 ;;
        *) CONFIG["THEME_COLOR"]=2 ;;
    esac
    
    save_config
    touch "${DATA_DIR}/.initialized"
    
    echo ""
    echo "Setup complete! Press Enter to continue..."
    read -r
}

# === SAVE CONFIG ===
save_config() {
    {
        echo "# StudyOS Configuration"
        echo "# Auto-generated on $(date)"
        echo ""
        for key in "${!CONFIG[@]}"; do
            [[ -n "$key" ]] && echo "${key}=${CONFIG[$key]}"
        done
    } > "$CONFIG_FILE"
}

# ============================================================================
# SEKCJA 3: UTILITY FUNCTIONS (linie 301-500)
# ============================================================================

# === LOGGING ===
log_message() {
    local level="$1"
    local message="$2"
    local timestamp
    timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    
    if [[ "${CONFIG[DEBUG_MODE]:-false}" == "true" ]]; then
        echo "[$timestamp] $level: $message" >> "${DATA_DIR}/debug.log"
    fi
    
    if [[ "$level" == "ERROR" ]]; then
        ERROR_MESSAGE="$message"
    elif [[ "$level" == "SUCCESS" ]]; then
        SUCCESS_MESSAGE="$message"
    fi
}

# === LOG STATS ===
log_stats() {
    local module="$1"
    local action="$2"
    local duration="${3:-0}"
    local metadata="${4:-}"
    
    local timestamp
    timestamp=$(date '+%s')
    
    echo "${timestamp}|${module}|${action}|${duration}|${metadata}" >> "$STATS_FILE"
}

# === SANITIZE INPUT (Wzmocnione) ===
sanitize_input() {
    local input="$1"
    
    # Wymiana Pipe na specjalny symbol w treści
    input="${input//|/__PIPE__}"
    
    # Usuń znaki niebezpieczne
    input="${input//;/_}"
    input="${input//&/_}"
    input="${input//\$/_}"
    input="${input//\`/_}"
    input="${input//\\/_}"
    
    # Usuń wiodące/końcowe spacje (lepiej użyć xargs)
    input=$(echo "$input" | xargs)
    
    echo "$input"
}

# === UNSANITIZE OUTPUT (Przywrócenie Pipe) ===
unsanitize_output() {
    local output="$1"
    output="${output//__PIPE__/|}"
    echo "$output"
}

# === GENERATE UNIQUE ID ===
generate_id() {
    # Format: timestamp_pid_random
    echo "$(date +%s)_$$_$RANDOM"
}

# === DATE FUNCTIONS ===
get_timestamp() {
    date '+%Y-%m-%d %H:%M:%S'
}

get_date() {
    date '+%Y-%m-%d'
}

seconds_to_human() {
    local seconds="${1:-0}"
    # Zapewnienie, że seconds to liczba
    if ! [[ "$seconds" =~ ^[0-9]+$ ]]; then
        echo "0s"
        return
    fi

    local hours=$((seconds / 3600))
    local minutes=$(( (seconds % 3600) / 60 ))
    local secs=$((seconds % 60))
    
    if (( hours > 0 )); then
        printf "%dh %dm %ds" "$hours" "$minutes" "$secs"
    elif (( minutes > 0 )); then
        printf "%dm %ds" "$minutes" "$secs"
    else
        printf "%ds" "$secs"
    fi
}

# === FILE LOCKING ===
lock_file() {
    local file="$1"
    local lockfile="${file}.lock"
    local timeout=10
    
    while [[ -f "$lockfile" ]] && (( timeout-- > 0 )); do
        sleep 0.1
    done
    
    if (( timeout <= 0 )); then
        log_message "ERROR" "Failed to lock file: $file"
        return 1
    fi
    
    # Używamy flock zamiast prostego 'echo $$ >' dla atomowości (jeśli dostępne, w przeciwnym razie fallback)
    if command -v flock &>/dev/null; then
        flock -n 9
        if [[ $? -eq 0 ]]; then
            echo $$ > "$lockfile"
            return 0
        else
            log_message "ERROR" "Failed to lock file with flock: $file"
            return 1
        fi
    else
        # Fallback
        echo $$ > "$lockfile"
        return 0
    fi
}

unlock_file() {
    local file="$1"
    rm -f "${file}.lock" 2>/dev/null
}

# === BACKUP FUNCTIONS ===
create_backup() {
    local backup_name="backup_$(date +%Y%m%d_%H%M%S).tar.gz"
    local backup_path="${DATA_DIR}/backups/${backup_name}"
    
    # Dodane flag -P (nie podążaj za linkami) i obsługa błędów tar
    tar -czf "$backup_path" -P -C "$DATA_DIR" \
        notes.txt todo.txt flashcards.txt habits.txt calendar.txt \
        pomodoro.log stats.log config.conf 2>/dev/null
    
    if [[ $? -eq 0 ]]; then
        log_message "SUCCESS" "Backup created: $backup_name"
        
        # Keep only last 10 backups
        cd "${DATA_DIR}/backups" || return
        ls -t backup_*.tar.gz | tail -n +11 | xargs -r rm --
    else
        log_message "ERROR" "Backup failed"
    fi
}

# ============================================================================
# SEKCJA 4: RENDERING ENGINE (linie 501-800)
# ============================================================================

# === SCREEN INIT ===
init_screen() {
    update_screen_size
    clear_screen
    tput civis  # Hide cursor
}

# === UPDATE SCREEN SIZE ===
update_screen_size() {
    SCREEN_WIDTH=$(tput cols)
    SCREEN_HEIGHT=$(tput lines)
    
    # Dodano || true, aby zapobiec wyjściu, gdy warunek jest fałszywy
    (( SCREEN_WIDTH < 80 )) && SCREEN_WIDTH=80 || true
    (( SCREEN_HEIGHT < 24 )) && SCREEN_HEIGHT=24 || true
    return 0
}

# === CLEAR SCREEN ===
clear_screen() {
    tput clear
}

# === CURSOR OPERATIONS ===
move_cursor() {
    local row="$1"
    local col="$2"
    tput cup "$row" "$col"
}

hide_cursor() {
    tput civis
}

show_cursor() {
    tput cnorm
}

# === COLOR FUNCTIONS ===
set_color() {
    local color="$1"
    tput setaf "$color"
}

reset_color() {
    tput sgr0
}

set_bold() {
    tput bold
}

set_dim() {
    tput dim
}

set_reverse() {
    tput rev
}

# === BORDER CHARACTERS ===
get_border_chars() {
    case "$THEME_BORDER" in
        single)
            echo "┌ ┐ └ ┘ ─ │"
            ;;
        double)
            echo "╔ ╗ ╚ ╝ ═ ║"
            ;;
        rounded)
            echo "╭ ╮ ╰ ╯ ─ │"
            ;;
        classic|*)
            echo "+ + + + - |"
            ;;
    esac
}

# === DRAW BOX ===
draw_box() {
    local x="$1" y="$2" width="$3" height="$4"
    local title="${5:-}"
    
    local borders
    read -r TL TR BL BR H V <<< "$(get_border_chars)"
    
    set_color "$THEME_COLOR"
    
    # Top border
    move_cursor "$y" "$x"
    if [[ -n "$title" ]]; then
        local max_title_len=$((width - 4))
        local title_text=" ${title} "
        if (( ${#title_text} > max_title_len )); then
            title_text="${title_text:0:max_title_len-1}…"
        fi
        local title_len=${#title_text}
        local remaining=$((width - title_len - 2))
        local half_pad=$((remaining / 2))
        local extra_pad=$((remaining % 2))
        
        printf "%s" "$TL"
        printf "%${half_pad}s" | tr ' ' "$H"
        printf "%s" "$title_text"
        printf "%$((half_pad + extra_pad))s" | tr ' ' "$H"
        printf "%s" "$TR"
    else
        printf "%s%$((width - 2))s%s" "$TL" "" "$TR" | tr ' ' "$H"
    fi
    
    # Vertical sides
    for ((i=1; i<height-1; i++)); do
        move_cursor $((y + i)) "$x"
        printf "%s" "$V"
        move_cursor $((y + i)) $((x + 1))
        printf "%$((width - 2))s" " " # Clear content area
        move_cursor $((y + i)) $((x + width - 1))
        printf "%s" "$V"
    done
    
    # Bottom border
    move_cursor $((y + height - 1)) "$x"
    printf "%s%$((width - 2))s%s" "$BL" "" "$BR" | tr ' ' "$H"
    
    reset_color
}

# === TEXT FUNCTIONS ===
center_text() {
    local text="$1"
    local width="${2:-$SCREEN_WIDTH}"
    local len=${#text}
    local padding=$(( (width - len) / 2 ))
    
    (( padding < 0 )) && padding=0
    
    printf "%*s" "$padding" ""
    set_bold
    set_color "$THEME_COLOR"
    printf "%s" "$text"
    reset_color
    printf "\n"
}

wrap_text() {
    local text="$1"
    local width="$2"
    
    if command -v fold &>/dev/null; then
        echo "$text" | fold -s -w "$width"
    else
        local words
        read -ra words <<< "$text"
        local line=""
        local output=""
        
        for word in "${words[@]}"; do
            if (( ${#line} + ${#word} + 1 > width )); then
                output+="$line"$'\n'
                line="$word"
            else
                [[ -n "$line" ]] && line+=" "
                line+="$word"
            fi
        done
        output+="$line"
        echo "$output"
    fi
}

# === DRAW WINDOW ===
draw_window() {
    local x="$1" y="$2" width="$3" height="$4"
    local title="$5"
    shift 5
    local content=("$@")
    
    draw_box "$x" "$y" "$width" "$height" "$title"
    
    local content_y=$((y + 1))
    local content_x=$((x + 1))
    local content_width=$((width - 2))
    local max_lines=$((height - 2))
    local line_count=0
    
    for line in "${content[@]}"; do
        [[ $line_count -ge $max_lines ]] && break
        
        local wrapped
        wrapped=$(wrap_text "$line" "$content_width")
        
        while IFS= read -r wrapped_line; do
            [[ $line_count -ge $max_lines ]] && break
            
            move_cursor $((content_y + line_count)) "$content_x"
            printf "%-${content_width}s" "$(unsanitize_output "$wrapped_line")"
            
            ((line_count++))
        done <<< "$wrapped"
    done
}

# === PROGRESS BAR ===
draw_progress_bar() {
    local x="$1" y="$2" width="$3"
    local current="$4" total="$5"
    local label="${6:-}"
    
    local percentage=$((current * 100 / total))
    local filled=$((width * current / total))
    local empty=$((width - filled))
    
    if (( total == 0 )); then filled=0; empty=$width; percentage=0; fi
    
    move_cursor "$y" "$x"
    set_color "$THEME_COLOR"
    
    printf "["
    printf "%${filled}s" | tr ' ' '='
    printf "%${empty}s" | tr ' ' '-'
    printf "] %3d%%" "$percentage"
    
    if [[ -n "$label" ]]; then
        printf " %s" "$label"
    fi
    
    reset_color
}

# === ANIMATED DRAW ===
animate_text() {
    local text="$1"
    local speed="${ANIMATION_SPEED:-0.02}"
    
    if [[ "$ANIMATION_ENABLED" != "true" ]]; then
        echo "$text"
        return
    fi
    
    for (( i=0; i<${#text}; i++ )); do
        printf "%c" "${text:$i:1}"
        sleep "$speed"
    done
    echo
}

# === MENU / LIST ===
draw_menu() {
    local x="$1" y="$2" width="$3"
    shift 3
    local items=("$@")
    local selected="${MENU_SELECTED:-0}"
    local max_display_items=$((SCREEN_HEIGHT - y - 2)) 
    
    local max_index=$(( ${#items[@]} - 1 ))
    if (( selected > max_index && max_index >= 0 )); then
        MENU_SELECTED=$max_index
        selected=$max_index
    elif (( selected < 0 )); then
        MENU_SELECTED=0
        selected=0
    fi
    
    local start_index=0
    local end_index=${#items[@]}
    
    if (( ${#items[@]} > max_display_items )); then
        if (( selected >= max_display_items )); then
            start_index=$((selected - max_display_items + 1))
        fi
        end_index=$((start_index + max_display_items))
        if (( end_index > ${#items[@]} )); then
            end_index=${#items[@]}
            start_index=$((end_index - max_display_items))
        fi
        if (( start_index < 0 )); then start_index=0; fi
    fi
    
    local display_index=0
    for ((i=start_index; i<end_index; i++)); do
        local item="${items[i]}"
        move_cursor $((y + display_index)) "$x"
        
        if [[ $i -eq $selected ]]; then
            set_reverse
            set_color "$THEME_COLOR"
            printf " > %-${width}s" "$item"
            reset_color
        else
            printf "   %-${width}s" "$item"
        fi
        
        ((display_index++))
    done
}

draw_welcome_screen() {
    local welcome_text="Welcome to StudyOS v$VERSION"
    move_cursor 5 "$(( (SCREEN_WIDTH - ${#welcome_text}) / 2 ))"
    animate_text "$welcome_text"
    sleep 0.5
    
    local motto="Your terminal productivity companion."
    move_cursor 7 "$(( (SCREEN_WIDTH - ${#motto}) / 2 ))"
    animate_text "$motto"
    sleep 1
    clear_screen
}

# ============================================================================
# SEKCJA 5: DATA MANAGEMENT (linie 801-1000)
# ============================================================================

# === GET ALL RECORDS ===
get_all_records() {
    local file="$1"
    if [[ ! -f "$file" ]]; then
        log_message "ERROR" "Data file not found: $file"
        return 1
    fi
    
    # Zapewnienie, że grep jest uruchamiany w podshellu, aby nie złamać set -e
    (grep -vE '^\s*#|^\s*$' "$file" || true)
}

# === GET RECORD BY ID ===
get_record_by_id() {
    local file="$1"
    local id="$2"
    
    get_all_records "$file" | grep "^$id|" | head -n 1
}

# === ADD RECORD ===
add_record() {
    local file="$1"
    local new_record="$2"
    
    if lock_file "$file"; then
        echo "$new_record" >> "$file"
        unlock_file "$file"
        log_message "SUCCESS" "Record added to $(basename "$file")"
        return 0
    else
        return 1
    fi
}

# === UPDATE RECORD (Poprawione użycie sed -i) ===
update_record() {
    local file="$1"
    local id="$2"
    local new_content="$3" 
    
    if lock_file "$file"; then
        # Używamy sed do podmiany linii zaczynającej się od ID, 
        # zapisując w tle i podmieniając, aby uniknąć problemów z różnymi wersjami sed
        if ! sed -i.bak "/^$id|/c\\$new_content" "$file"; then
            log_message "ERROR" "Failed to update record $id in $file"
            rm -f "${file}.bak"
            unlock_file "$file"
            return 1
        fi
        rm -f "${file}.bak"
        unlock_file "$file"
        log_message "SUCCESS" "Record $id updated in $(basename "$file")"
        return 0
    else
        return 1
    fi
}

# === DELETE RECORD ===
delete_record() {
    local file="$1"
    local id="$2"
    
    if lock_file "$file"; then
        # Używamy grep -v do wykluczenia linii zaczynającej się od ID i zapisujemy do pliku tymczasowego
        if ! (grep -v "^$id|" "$file" > "${file}.tmp" || true); then
            log_message "ERROR" "Failed to create temp file for deletion."
            unlock_file "$file"
            return 1
        fi
        mv "${file}.tmp" "$file"
        unlock_file "$file"
        log_message "SUCCESS" "Record $id deleted from $(basename "$file")"
        return 0
    else
        return 1
    fi
}

# ============================================================================
# SEKCJA 6: MODULES - Notes (linie 1001-1100)
# ============================================================================

notes_get_list() {
    # Zwraca ID|Tytuł (Tagi)
    get_all_records "$NOTES_FILE" | awk -F '|' '{print $1"|"$3" ("$5")"}'
}

notes_view() {
    CURRENT_MODULE="Notes"
    local notes_list
    notes_list=$(notes_get_list)
    
    local notes_array=()
    readarray -t notes_array <<< "$notes_list"
    
    local window_height=$((SCREEN_HEIGHT - 4))
    local title="Notes (${#notes_array[@]} items) [j/k:move, a:add, d:del, v:view/edit]"
    
    draw_window 1 1 $((SCREEN_WIDTH - 2)) "$window_height" "$title"
    
    if (( ${#notes_array[@]} == 0 )); then
        move_cursor 2 2
        printf "No notes found. Press 'a' to add one."
        return
    fi
    
    local display_items=()
    for item in "${notes_array[@]}"; do
        display_items+=("$(echo "$item" | cut -d'|' -f2-)")
    done
    
    draw_menu 2 2 $((SCREEN_WIDTH - 6)) "${display_items[@]}"
}

notes_add() {
    local title
    local content
    local tags
    
    title=$(get_user_input "Note Title (max 50 chars)")
    [[ -z "$title" ]] && { log_message "WARNING" "Adding note cancelled."; return; }
    
    # Użycie edytora systemowego (np. $EDITOR lub nano) dla treści
    echo "# Enter your note content here. Save and exit to finish." > "$TEMP_FILE"
    if [[ -n "$EDITOR" ]]; then
        $EDITOR "$TEMP_FILE"
    elif command -v nano &>/dev/null; then
        nano "$TEMP_FILE"
    else
        log_message "ERROR" "No text editor found (try setting \$EDITOR or install nano)."
        return
    fi
    
    content=$(cat "$TEMP_FILE" | grep -v '^#' | tr '\n' ' ' | xargs)
    rm -f "$TEMP_FILE"
    
    tags=$(get_user_input "Tags (comma separated, optional)")
    
    local id=$(generate_id)
    local timestamp=$(get_timestamp)
    local sanitized_title=$(sanitize_input "$title")
    local sanitized_content=$(sanitize_input "$content")
    local sanitized_tags=$(sanitize_input "$tags")
    
    local new_record="${id}|${timestamp}|${sanitized_title}|${sanitized_content}|${sanitized_tags}"
    add_record "$NOTES_FILE" "$new_record"
    
    NEEDS_REDRAW=true
    CURRENT_VIEW="notes_view"
}

# ============================================================================
# SEKCJA 7: MODULES - TODO (linie 1101-1200)
# ============================================================================

todo_get_list() {
    get_all_records "$TODO_FILE" | awk -F '|' '
        BEGIN {
            priority[1]="[H]"
            priority[2]="[M]"
            priority[3]="[L]"
            status["pending"]="[ ]"
            status["in_progress"]="[>]"
            status["done"]="[x]"
            OFS="|"
        }
        {
            # Przywrócenie pierwotnych wartości z uwzględnieniem odsanitowania
            title = $6
            
            # Wypisujemy: ID|Status Priority Tytuł (Projekt)
            print $1, status[$5] priority[$4] " " title " ("$7")"
        }
    '
}

todo_view() {
    CURRENT_MODULE="TODO"
    local todo_list
    todo_list=$(todo_get_list)
    
    local todo_array=()
    readarray -t todo_array <<< "$todo_list"
    
    local window_height=$((SCREEN_HEIGHT - 4))
    local title="TODO List (${#todo_array[@]} tasks) [j/k:move, a:add, d:del, t:toggle status]"
    
    draw_window 1 1 $((SCREEN_WIDTH - 2)) "$window_height" "$title"
    
    if (( ${#todo_array[@]} == 0 )); then
        move_cursor 2 2
        printf "No tasks found. Press 'a' to add one."
        return
    fi
    
    local display_items=()
    for item in "${todo_array[@]}"; do
        display_items+=("$(echo "$item" | cut -d'|' -f2-)")
    done
    
    draw_menu 2 2 $((SCREEN_WIDTH - 6)) "${display_items[@]}"
}

todo_add() {
    local title
    title=$(get_user_input "Task Title")
    [[ -z "$title" ]] && { log_message "WARNING" "Adding task cancelled."; return; }
    
    local priority_input=$(get_user_input "Priority (1=H, 2=M, 3=L) [2]" 2)
    local priority=2
    if [[ "$priority_input" =~ ^[1-3]$ ]]; then
        priority="$priority_input"
    fi
    
    local project=$(get_user_input "Project (optional)")
    
    local id=$(generate_id)
    local created=$(get_date)
    local sanitized_title=$(sanitize_input "$title")
    local sanitized_project=$(sanitize_input "$project")
    
    # Format: ID|created|due|priority|status|title|project|tags
    local new_record="${id}|${created}| |${priority}|pending|${sanitized_title}|${sanitized_project}|"
    add_record "$TODO_FILE" "$new_record"
    
    NEEDS_REDRAW=true
    CURRENT_VIEW="todo_view"
}

todo_toggle_status() {
    local selected_line
    # Poprawka: upewnij się, że wybrany rekord istnieje
    selected_line=$(get_all_records "$TODO_FILE" | head -n $((MENU_SELECTED + 1)) | tail -n 1)
    [[ -z "$selected_line" ]] && { log_message "ERROR" "No task selected to toggle."; return; }
    
    local id=$(echo "$selected_line" | cut -d'|' -f1)
    local status=$(echo "$selected_line" | cut -d'|' -f5)
    
    local new_status
    if [[ "$status" == "done" ]]; then
        new_status="pending"
    else
        new_status="done"
    fi
    
    # Używamy awk do bezpiecznej podmiany tylko pola statusu
    local new_record
    new_record=$(echo "$selected_line" | awk -F '|' -v OFS='|' -v new_status="$new_status" '{$5 = new_status; print}')
    
    update_record "$TODO_FILE" "$id" "$new_record"
    NEEDS_REDRAW=true
}

# ============================================================================
# SEKCJA 8: MODULES - Pomodoro (linie 1201-1300)
# ============================================================================

pomo_timer_loop() {
    # Skrypt uruchamiany w tle
    local duration_secs=$1
    local type=$2
    local parent_pid=$3
    
    local end_time=$(( $(date +%s) + duration_secs ))
    
    while (( $(date +%s) < end_time )); do
        # Co sekundę wysyłamy sygnał odświeżania do procesu głównego
        sleep 1
        kill -USR1 "$parent_pid" 2>/dev/null || break # Jeśli parent zniknął, kończymy
    done
    
    # Zakończone
    log_message "SUCCESS" "Pomodoro $type finished!"
    
    # Zapis logu (uproszczone)
    local duration_min=$((duration_secs / 60))
    echo "$(date +%s)|${duration_min}|Task Placeholder|yes|" >> "$POMO_LOG"
    
    # Sygnał do rodzica do pełnego odświeżenia i aktualizacji stanu
    kill -USR1 "$parent_pid" 2>/dev/null || true
    
    # Wychodzimy z pętli
    exit 0
}

pomo_start() {
    [[ "$POMODORO_RUNNING" == "true" ]] && { log_message "ERROR" "Pomodoro is already running."; return; }
    
    local duration_min="${CONFIG[POMODORO_DURATION]:-25}"
    POMODORO_DURATION_SECS=$((duration_min * 60))
    POMODORO_START_TIME=$(date +%s)
    
    # Uruchomienie loopu w tle
    pomo_timer_loop "$POMODORO_DURATION_SECS" "work" $$ &
    
    POMODORO_PID=$!
    POMODORO_RUNNING=true
    log_message "INFO" "Pomodoro work started (PID: $POMODORO_PID) for ${duration_min} minutes."
    NEEDS_REDRAW=true
}

pomo_stop() {
    [[ "$POMODORO_RUNNING" == "false" ]] && { log_message "WARNING" "Pomodoro is not running."; return; }
    
    # Wysyłanie sygnału SIGTERM do zakończenia pętli timera
    kill "$POMODORO_PID" 2>/dev/null || true
    
    POMODORO_RUNNING=false
    POMODORO_PID=""
    POMODORO_START_TIME=0
    POMODORO_DURATION_SECS=0
    log_message "INFO" "Pomodoro stopped."
    NEEDS_REDRAW=true
}

pomo_view() {
    local content=()
    local x=32 y=1 width=30 height=10
    
    if [[ "$POMODORO_RUNNING" == "true" ]]; then
        local elapsed=$(( $(date +%s) - POMODORO_START_TIME ))
        local remaining=$(( POMODORO_DURATION_SECS - elapsed ))
        
        if (( remaining < 0 )); then remaining=0; pomo_stop; return; fi
        
        content+=("Status: WORK (Task: StudyOS)")
        content+=("Elapsed: $(seconds_to_human "$elapsed")")
        content+=("Remaining: $(seconds_to_human "$remaining")")
        content+=("")
        content+=("Press 's' to stop.")
        
        # Rysowanie paska postępu
        local bar_width=$((width - 4))
        move_cursor $((y + 6)) $((x + 2))
        draw_progress_bar $((x + 2)) $((y + 6)) "$bar_width" "$elapsed" "$POMODORO_DURATION_SECS"
    else
        local duration="${CONFIG[POMODORO_DURATION]:-25}"
        content+=("Status: STOPPED (Duration: ${duration} min)")
        content+=("Total Pomodoros: $(grep -c 'work' "$POMO_LOG" 2>/dev/null || echo 0)")
        content+=("")
        content+=("Press 's' to start work.")
    fi
    
    draw_window "$x" "$y" "$width" "$height" "Pomodoro Timer" "${content[@]}"
}

# ============================================================================
# SEKCJA 9: MODULES - Flashcards (linie 1301-1400)
# ============================================================================

flashcards_get_due() {
    local current_date=$(get_date)
    # Zwraca ID|Deck - Pytanie
    get_all_records "$FLASH_FILE" | awk -F '|' -v current_date="$current_date" '
        {
            if ($7 <= current_date) {
                print $1"|"$2" - "$3
            }
        }
    '
}

flashcards_view() {
    CURRENT_MODULE="Flashcards"
    local due_cards
    due_cards=$(flashcards_get_due)
    
    local cards_array=()
    readarray -t cards_array <<< "$due_cards"
    
    local window_height=$((SCREEN_HEIGHT - 4))
    local title="Flashcards (${#cards_array[@]} due) [j/k:move, a:add, r:review]"
    
    draw_window 1 1 $((SCREEN_WIDTH - 2)) "$window_height" "$title"
    
    if (( ${#cards_array[@]} == 0 )); then
        move_cursor 2 2
        printf "No flashcards are due for review. Press 'a' to add one."
        return
    fi
    
    local display_items=()
    for item in "${cards_array[@]}"; do
        display_items+=("$(echo "$item" | cut -d'|' -f2-)")
    done
    
    draw_menu 2 2 $((SCREEN_WIDTH - 6)) "${display_items[@]}"
}

# ============================================================================
# SEKCJA 10: MODULES - Calendar (linie 1401-1500)
# ============================================================================

calendar_get_today() {
    local today=$(get_date)
    # Zwraca Czas (Tytuł) - Typ
    get_all_records "$CALENDAR_FILE" | grep -E "^[^|]*\|${today}\|" | awk -F '|' '{print $3" ("$4") - "$5}'
}

calendar_view() {
    CURRENT_MODULE="Calendar"
    local today_events
    today_events=$(calendar_get_today)
    
    local events_array=()
    readarray -t events_array <<< "$today_events"
    
    local x=32 y=12 width=30 height=10
    local content=("Today's Events ($(get_date))")
    content+=("-------------------------")
    
    if (( ${#events_array[@]} == 0 )); then
        content+=("No events scheduled for today.")
    else
        for event in "${events_array[@]}"; do
            content+=("$event")
        done
    fi
    
    draw_window "$x" "$y" "$width" "$height" "Calendar" "${content[@]}"
}

# ============================================================================
# SEKCJA 11: MODULES - Stats/Graphs (linie 1501-1600)
# ============================================================================

stats_get_summary() {
    local total_pomos=$(grep -c 'work' "$POMO_LOG" 2>/dev/null || echo 0)
    local total_notes=$(grep -vE '^\s*#|^\s*$' "$NOTES_FILE" 2>/dev/null | wc -l || echo 0)
    local total_tasks=$(grep -vE '^\s*#|^\s*$' "$TODO_FILE" 2>/dev/null | wc -l || echo 0)
    local done_tasks=$(grep '|done|' "$TODO_FILE" 2>/dev/null | wc -l || echo 0)
    
    echo "Pomodoros: $total_pomos"
    echo "Notes: $total_notes"
    echo "Tasks: $total_tasks (Done: $done_tasks)"
}

stats_view() {
    CURRENT_MODULE="Stats"
    local summary
    summary=$(stats_get_summary)
    
    local summary_array=()
    readarray -t summary_array <<< "$summary"
    
    local x=32 y=23 width=30 height=10 # Przesunięte w dół dla lepszego layoutu
    draw_window "$x" "$y" "$width" "$height" "Stats Summary" "${summary_array[@]}"
}

# ============================================================================
# SEKCJA 12: MODULES - Internet (Weather/Quotes/News) (linie 1601-1700)
# ============================================================================

fetch_weather() {
    local city="${CONFIG[WEATHER_CITY]:-Warsaw}"
    local units="${CONFIG[WEATHER_UNITS]:-metric}"
    local appid="YOUR_OPENWEATHERMAP_API_KEY" # Zmień na prawdziwy klucz API
    
    if [[ "$ONLINE_MODE" != "true" ]]; then
        log_message "WARNING" "Offline mode - cannot fetch weather."
        return
    fi
    
    if (( $(date +%s) - LAST_REFRESH < REFRESH_INTERVAL )) && [[ -f "$WEATHER_CACHE" ]]; then
        return # Używamy cache
    fi
    
    local url="http://api.openweathermap.org/data/2.5/weather?q=$city&units=$units&appid=$appid"
    
    # Pobieranie danych i sprawdzanie, czy się powiodło
    if curl -s --max-time 5 "$url" > "$WEATHER_CACHE.tmp" && [[ -s "$WEATHER_CACHE.tmp" ]]; then
        mv "$WEATHER_CACHE.tmp" "$WEATHER_CACHE"
        LAST_REFRESH=$(date +%s)
        log_message "INFO" "Weather fetched for $city."
    else
        log_message "ERROR" "Failed to fetch weather for $city."
        rm -f "$WEATHER_CACHE.tmp"
    fi
}

get_cached_weather() {
    if [[ -f "$WEATHER_CACHE" ]]; then
        # Bardzo uproszczony parser (może wymagać jq, ale używamy grep/sed dla czystego Basha)
        local temp
        temp=$(grep -o '"temp":[0-9]*\.[0-9]*' "$WEATHER_CACHE" | cut -d':' -f2 | cut -d'.' -f1 || echo "N/A")
        local desc
        desc=$(grep -o '"description":"[^"]*"' "$WEATHER_CACHE" | head -n 1 | cut -d':' -f2 | tr -d '"' || echo "N/A")
        local city="${CONFIG[WEATHER_CITY]:-Warsaw}"
        
        echo "$city: ${temp}°C / ${desc}"
    else
        echo "Weather N/A (Offline/Stale)"
    fi
}

# ============================================================================
# SEKCJA 13: MODULES - Misc (Calc/Files/Search) (linie 1701-1800)
# ============================================================================

calculate() {
    if ! command -v bc &>/dev/null; then
        log_message "ERROR" "bc dependency missing."
        return 1
    fi
    
    local expression="$1"
    
    if [[ -z "$expression" ]]; then
        log_message "ERROR" "No expression provided."
        return 1
    fi
    
    # Użycie bc z dokładnością 4
    echo "scale=4; $expression" | bc -l
}

# ============================================================================
# SEKCJA 14: UI & MAIN LOOP (linie 1801-2000)
# ============================================================================

# === INPUT MANAGEMENT (Wprowadzenie dedykowanego trybu input) ===
# get_user_input: synchroniczna funkcja do pobierania linii tekstu z terminala
get_user_input() {
    local prompt="$1"
    local default_value="${2:-}"
    local input_line=""
    local cursor_pos=2
    
    # Włączamy kursor i przechodzimy na dół ekranu
    show_cursor
    move_cursor $((SCREEN_HEIGHT - 1)) 0
    printf "%-${SCREEN_WIDTH}s" " " # Czyścimy linię
    
    set_color "$THEME_COLOR"
    printf " %s: " "$prompt"
    reset_color
    
    # Ustawiamy kursor do wpisywania
    move_cursor $((SCREEN_HEIGHT - 1)) $cursor_pos
    
    # Odczytujemy linię z terminala
    read -r input_line
    
    # Czyścimy linię po zakończeniu inputu
    move_cursor $((SCREEN_HEIGHT - 1)) 0
    printf "%-${SCREEN_WIDTH}s" " "
    hide_cursor
    NEEDS_REDRAW=true
    
    # Zwracamy wartość domyślną, jeśli input był pusty
    if [[ -z "$input_line" && -n "$default_value" ]]; then
        echo "$default_value"
    else
        echo "$input_line"
    fi
}

input_handler() {
    local key_input="$1"
    
    case "$key_input" in
        # Global Keys
        "${CONFIG[KEY_QUIT]:-q}") cleanup_and_exit ;;
        "${CONFIG[KEY_HELP]:-?}") CURRENT_VIEW="help" ; NEEDS_REDRAW=true ;;
        "b") create_backup ; NEEDS_REDRAW=true ;;
        "r") check_internet_connection ; fetch_weather ; NEEDS_REDRAW=true ;;
        
        # View Navigation (d-dashboard, n-notes, t-todo, f-flashcards, p-pomodoro)
        "d") CURRENT_VIEW="dashboard" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        "n") CURRENT_VIEW="notes_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        "t") CURRENT_VIEW="todo_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        "p") CURRENT_VIEW="pomo_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        "f") CURRENT_VIEW="flashcards_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        "c") CURRENT_VIEW="calendar_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
        
        # Action Key 'a' (Add)
        "a")
            case "$CURRENT_VIEW" in
                "notes_view") notes_add ;;
                "todo_view") todo_add ;;
                *) log_message "WARNING" "Action 'a' not supported in $CURRENT_VIEW view." ;;
            esac
            NEEDS_REDRAW=true
            ;;
            
        # Action Key 'd' (Delete)
        "d")
            case "$CURRENT_VIEW" in
                "notes_view") 
                    local id=$(notes_get_list | head -n $((MENU_SELECTED + 1)) | tail -n 1 | cut -d'|' -f1)
                    if [[ -n "$id" && "${CONFIG[CONFIRM_DELETE]:-true}" == "true" ]]; then
                         local confirm=$(get_user_input "Confirm delete ID $id? (y/N)" "N")
                         [[ "$confirm" =~ ^[yY]$ ]] && delete_record "$NOTES_FILE" "$id"
                    fi
                    ;;
                "todo_view")
                    local id=$(todo_get_list | head -n $((MENU_SELECTED + 1)) | tail -n 1 | cut -d'|' -f1)
                    if [[ -n "$id" ]]; then
                         local confirm=$(get_user_input "Confirm delete ID $id? (y/N)" "N")
                         [[ "$confirm" =~ ^[yY]$ ]] && delete_record "$TODO_FILE" "$id"
                    fi
                    ;;
                *) log_message "WARNING" "Action 'd' not supported in $CURRENT_VIEW view." ;;
            esac
            NEEDS_REDRAW=true
            ;;

        # Pomodoro Actions (Start/Stop)
        "s")
            if [[ "$CURRENT_VIEW" == "pomo_view" || "$CURRENT_VIEW" == "dashboard" ]]; then
                [[ "$POMODORO_RUNNING" == "true" ]] && pomo_stop || pomo_start
            fi
            NEEDS_REDRAW=true
            ;;
            
        # TODO Actions (Toggle Status)
        "t")
            [[ "$CURRENT_VIEW" == "todo_view" ]] && todo_toggle_status
            NEEDS_REDRAW=true
            ;;

        # Navigation Keys (j/k - vim style)
        "${CONFIG[KEY_UP]:-k}") (( MENU_SELECTED > 0 )) && MENU_SELECTED=$((MENU_SELECTED - 1)); NEEDS_REDRAW=true ;;
        "${CONFIG[KEY_DOWN]:-j}") MENU_SELECTED=$((MENU_SELECTED + 1)); NEEDS_REDRAW=true ;;
        
        *) #log_message "INFO" "Unknown key: $key_input" 
           # Przechodzenie do widoków menu
           if [[ "$CURRENT_VIEW" == "dashboard" ]]; then
               case "$MENU_SELECTED" in
                   0) CURRENT_VIEW="dashboard" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
                   1) CURRENT_VIEW="notes_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
                   2) CURRENT_VIEW="todo_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
                   3) CURRENT_VIEW="flashcards_view" ; MENU_SELECTED=0 ; NEEDS_REDRAW=true ;;
                   *) log_message "INFO" "View not implemented." ;;
               esac
           fi
           ;;
    esac
}

draw_dashboard() {
    CURRENT_MODULE="Dashboard"
    
    # 1. Main Menu (Left Column)
    local menu_items=("Dashboard" "Notes (n)" "TODO (t)" "Flashcards (f)" "Pomodoro (p)" "Calendar (c)" "Stats" "Config" "Help (?)")
    local menu_height=${#menu_items[@]}
    local menu_width=25
    draw_window 1 1 "$menu_width" $((SCREEN_HEIGHT - 2)) "Menu (q:quit)"
    draw_menu 2 2 $((menu_width - 4)) "${menu_items[@]}"
    
    # 2. Pomodoro Box (Mid Right Top)
    pomo_view # Wywołuje draw_window 32 1 30 10
    
    # 3. Weather/Quote Box (Far Right Top)
    local weather_info=$(get_cached_weather)
    local quote_info="[Placeholder for quote]"
    local quote_lines=("${weather_info}" "---" "${quote_info}")
    draw_window $((SCREEN_WIDTH - 32)) 1 30 10 "Internet" "${quote_lines[@]}"
    
    # 4. Calendar Box (Mid Right Bottom)
    calendar_view # Wywołuje draw_window 32 12 30 10
    
    # 5. Stats Box (Far Right Bottom)
    stats_view # Wywołuje draw_window $((SCREEN_WIDTH - 32)) 12 30 10
    
    # 6. Notes/TODO preview (Bottom Left/Center) - Zostawmy na razie wolne miejsce
    
}

render_ui() {
    clear_screen
    
    # Kopiowanie i czyszczenie wiadomości
    local error_copy="$ERROR_MESSAGE"
    local success_copy="$SUCCESS_MESSAGE"
    ERROR_MESSAGE=""
    SUCCESS_MESSAGE=""
    
    # Header
    move_cursor 0 0
    set_color "$THEME_COLOR"
    set_bold
    printf "%-${SCREEN_WIDTH}s" " $SCRIPT_NAME v$VERSION | View: $CURRENT_VIEW | Status: $([[ "$ONLINE_MODE" == "true" ]] && echo "ONLINE" || echo "OFFLINE") | $(get_timestamp) "
    reset_color
    
    # Main View Switch
    case "$CURRENT_VIEW" in
        "dashboard") draw_dashboard ;;
        "notes_view") notes_view ;;
        "todo_view") todo_view ;;
        "pomo_view") pomo_view ;;
        "flashcards_view") flashcards_view ;;
        "calendar_view") calendar_view ;;
        "stats_view") stats_view ;;
        *) 
            draw_window 1 1 $((SCREEN_WIDTH - 2)) $((SCREEN_HEIGHT - 4)) "Error" "View '$CURRENT_VIEW' not implemented yet."
            draw_dashboard 
            ;;
    esac
    
    # Footer (Status/Error/Success Bar)
    move_cursor $((SCREEN_HEIGHT - 1)) 0
    set_dim
    printf "%-${SCREEN_WIDTH}s" " "
    move_cursor $((SCREEN_HEIGHT - 1)) 0
    
    if [[ -n "$error_copy" ]]; then
        set_color 1 # Red
        set_bold
        printf " ERROR: %s " "$error_copy"
    elif [[ -n "$success_copy" ]]; then
        set_color 2 # Green
        set_bold
        printf " SUCCESS: %s " "$success_copy"
    else
        printf " %s: Press '?' for help. | Active Module: $CURRENT_MODULE " "$SCRIPT_NAME"
    fi
    reset_color
    
    hide_cursor
    NEEDS_REDRAW=false
}

main_loop() {
    update_screen_size
    
    # Glowna pętla aplikacji
    while true; do
        # 1. Redraw
        if [[ "$NEEDS_REDRAW" == "true" ]]; then
            render_ui
        fi
        
        # 2. Auto-Refresh (Weather/Online)
        if (( $(date +%s) - LAST_REFRESH > REFRESH_INTERVAL )); then
            fetch_weather # Wewnątrz fetch_weather ustawia LAST_REFRESH
            NEEDS_REDRAW=true
        fi
        
        # 3. Get Non-Blocking Input (Command Mode)
        local key_input
        # Używamy read z timeoutem 0.1s dla non-blocking input
        read -r -n 1 -t 0.1 key_input || true
        
        if [[ -n "$key_input" ]]; then
            input_handler "$key_input"
        fi
        
        # Minimalne opóźnienie, aby nie obciążać CPU
        sleep 0.05 
    done
}


# ============================================================================
# SEKCJA 15: MAIN ENTRY POINT (linie 2001-2100)
# ============================================================================

main() {
    # Uruchomienie aplikacji
    init_app
    # Pętla główna
    main_loop
}

# --- Execute Main ---
main || true
