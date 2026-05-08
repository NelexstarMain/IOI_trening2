#!/bin/bash
set -e 

OUTPUT_FILE="CP4_STRUCTURE.md"
TARGET_DIR="CP4"

echo ">> INITIALIZING RETRO SCANNER..."

# --- LICZENIE STATYSTYK ---
TOTAL_KATTIS=$(find "$TARGET_DIR" -type d -name "kattis" -exec find {} -type f ! -name ".*" \; | wc -l | xargs)
TOTAL_UVA=$(find "$TARGET_DIR" -type d -name "uva" -exec find {} -type f ! -name ".*" \; | wc -l | xargs)
TOTAL_SUM=$((TOTAL_KATTIS + TOTAL_UVA))

cat << EOF > "$OUTPUT_FILE"
# CP4 STRUCTURE REPORT

<div style="background-color: #050505; color: #00ff00; padding: 25px; font-family: 'Courier New', monospace; border: 1px solid #00ff00; line-height: 1.1; text-transform: uppercase;">

<pre style="color: #00ff00; background: transparent; border: none; font-weight: bold; line-height: 1;">
  _   _   _   _  
 / \ / \ / \ / \ 
( C | P | 4 | )
 \_/ \_/ \_/ \_/ 

 [ UNIT: ROOT_DIRECTORY ]
 [ SECTOR: $(date '+%Y/%m/%d') ]
 [ ACCESS: GRANTED ]
</pre>

<hr style="border: 0; border-top: 1px solid #00ff00; margin: 20px 0;">

[DIR] CP4<br>
EOF

generate_tree_html() {
    local dir="$1"
    local prefix="$2"
    
    local items=("$dir"/*)
    local count=${#items[@]}
    local index=0
    
    for item in "${items[@]}"; do
        [ ! -e "$item" ] && continue
        index=$((index + 1))
        local base_name=$(basename "$item")
        [[ "$base_name" == .* ]] && continue
        
        local branch="|-- "
        [ "$index" -eq "$count" ] && branch="\`— "
        
        local indent="${prefix}${branch}"
        
        if [ -d "$item" ]; then
            # Logika zliczania dla folderów
            local folder_info=""
            if [[ "$base_name" == "kattis" || "$base_name" == "uva" ]]; then
                local sub_count=$(find "$item" -type f ! -name ".*" | wc -l | xargs)
                folder_info=" [FILES: ${sub_count}]"
            fi
            
            echo "${indent}[DIR] <b>${base_name}</b>${folder_info}<br>" >> "$OUTPUT_FILE"
            generate_tree_html "$item" "${prefix}|&nbsp;&nbsp;&nbsp;"
        else
            # Wyświetlanie plików bez emotek
            local ext="[EXE]"
            if [[ "$base_name" == *.cpp ]]; then ext="[CPP]"; fi
            if [[ "$base_name" == *.py ]]; then ext="[PY ]"; fi
            
            echo "${indent}${ext} ${base_name}<br>" >> "$OUTPUT_FILE"
        fi
    done
}

generate_tree_html "$TARGET_DIR" ""

cat << EOF >> "$OUTPUT_FILE"

<hr style="border: 0; border-top: 1px solid #00ff00; margin: 20px 0;">

<pre style="color: #00ff00; background: transparent; border: none; font-weight: bold;">
>> DATABASE SUMMARY
>> ---------------------------
>> KATTIS_ENTRIES: $TOTAL_KATTIS
>> UVA_ENTRIES:    $TOTAL_UVA
>> ---------------------------
>> TOTAL_RECORDS:  $TOTAL_SUM
>> ---------------------------
>> STATUS: ALL_FILES_SYNCED
</pre>

<div style="text-align: center; font-size: 0.7em; letter-spacing: 2px; margin-top: 20px;">
--- END OF DATA TRANSMISSION ---
</div>

</div>
EOF

echo ">> SCAN COMPLETE."

# --- GIT OPERATIONS ---
RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo ">> SYNCING WITH REMOTE SERVER..."
git add -A

if [ -z "$(git status --porcelain)" ]; then
    echo ">> NO CHANGES DETECTED. ABORTING."
    exit 0
fi

git commit -m "SYS_UPDATE: $RANDOM_STRING"
git pull --rebase --autostash
git push -u origin HEAD

echo ">> SYSTEM READY."