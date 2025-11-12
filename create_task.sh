#!/usr/bin/env bash
#
# CP Project Setup Script - Terminal Edition
# Version: 3.0
#

set -euo pipefail
IFS=$'\n\t'

# ============================================================================
# CONFIG
# ============================================================================

readonly VERSION="3.0"
readonly SCRIPT_NAME="$(basename "${BASH_SOURCE[0]}")"

# Terminal colors
readonly CLR_OFF='\e[0m'
readonly CLR_BOLD='\e[1m'
readonly CLR_DIM='\e[2m'
readonly CLR_CYAN='\e[36m'
readonly CLR_GREEN='\e[32m'
readonly CLR_RED='\e[31m'
readonly CLR_YELLOW='\e[33m'
readonly CLR_BLUE='\e[34m'
readonly CLR_GRAY='\e[90m'

# Base directories - customize for your setup
readonly -a BASE_DIRS=(
    "/mnt/c/Users/Nelek/Desktop/IOI_trening/CP4/Kattis"
    "/mnt/c/Users/Nelek/Desktop/IOI_trening/CP4/UVa"
    "/mnt/c/Users/Nelek/Desktop/IOI_trening/Inne_Zadania"
)

readonly FORBIDDEN_CHARS='/\:*?"<>|'

# ============================================================================
# TERMINAL OUTPUT
# ============================================================================

log_msg() {
    echo -e "${CLR_BLUE}│${CLR_OFF} $*" >&2
}

log_ok() {
    echo -e "${CLR_GREEN}│ [OK]${CLR_OFF} $*" >&2
}

log_err() {
    echo -e "${CLR_RED}│ [ERR]${CLR_OFF} $*" >&2
}

log_warn() {
    echo -e "${CLR_YELLOW}│ [!]${CLR_OFF} $*" >&2
}

log_input() {
    echo -e -n "${CLR_CYAN}│ >${CLR_OFF} $*" >&2
}

fatal() {
    echo -e "${CLR_RED}[FATAL]${CLR_OFF} $*" >&2
    exit 1
}

separator() {
    echo -e "${CLR_GRAY}│${CLR_OFF}" >&2
}

divider() {
    echo -e "${CLR_GRAY}├────────────────────────────────────────────────${CLR_OFF}" >&2
}

header_main() {
    clear
    echo -e "${CLR_CYAN}┌────────────────────────────────────────────────┐${CLR_OFF}"
    echo -e "${CLR_CYAN}│${CLR_OFF}  ${CLR_BOLD}CP PROJECT SETUP${CLR_OFF} ${CLR_DIM}v${VERSION}${CLR_OFF}                       ${CLR_CYAN}│${CLR_OFF}"
    echo -e "${CLR_CYAN}└────────────────────────────────────────────────┘${CLR_OFF}\n"
}

header_step() {
    local step="$1"
    local total="$2"
    local title="$3"
    echo -e "${CLR_BOLD}${CLR_CYAN}[${step}/${total}]${CLR_OFF} ${CLR_BOLD}${title}${CLR_OFF}"
    echo -e "${CLR_YELLOW}├──${CLR_OFF} ${CLR_DIM}$4${CLR_OFF}\n"
}

footer_step() {
    echo -e "${CLR_YELLOW}└──${CLR_OFF} ${CLR_GREEN}${CLR_BOLD}DONE${CLR_OFF}\n"
}

# ============================================================================
# UTILITIES
# ============================================================================

trim() {
    local var="$*"
    var="${var#"${var%%[![:space:]]*}"}"
    var="${var%"${var##*[![:space:]]}"}"
    printf '%s' "$var"
}

has_forbidden() {
    local str="$1"
    local -i i
    for ((i=0; i<${#str}; i++)); do
        [[ "$FORBIDDEN_CHARS" == *"${str:i:1}"* ]] && return 0
    done
    return 1
}

check_dir() {
    local dir="$1"
    [[ ! -d "$dir" ]] && { log_warn "Not found: $dir"; return 1; }
    [[ ! -w "$dir" ]] && { log_warn "No write access: $dir"; return 1; }
    return 0
}

ask_yn() {
    local question="$1"
    local default="${2:-y}"
    local response
    
    if [[ "$default" == "y" ]]; then
        log_input "$question [Y/n]: "
    else
        log_input "$question [y/N]: "
    fi
    
    read -r response
    response=$(echo "$response" | tr '[:upper:]' '[:lower:]')
    
    case "$response" in
        y|yes|t|tak|"") [[ "$default" == "y" ]] && return 0 || return 1 ;;
        n|no|nie) return 1 ;;
        *) [[ "$default" == "y" ]] && return 0 || return 1 ;;
    esac
}

# ============================================================================
# FILE TEMPLATES
# ============================================================================

template_cpp_multi() {
    cat <<'TEMPLATE'
#include <bits/stdc++.h>
using namespace std;

// Types
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

// Macros
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)((x).size())

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    // TODO: implement solution
    
}

int main() {
    fast_io();
    int t = 1;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
TEMPLATE
}

template_cpp_single() {
    cat <<'TEMPLATE'
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    
    // TODO: implement solution
    
    return 0;
}
TEMPLATE
}

template_generator() {
    cat <<'TEMPLATE'
#!/usr/bin/env python3
"""Test data generator"""

import random
import sys

def generate(seed):
    random.seed(seed)
    
    # Example: multiple test cases
    T = random.randint(1, 3)
    print(T)
    
    for _ in range(T):
        n = random.randint(2, 10)
        arr = [random.randint(-100, 100) for _ in range(n)]
        print(n)
        print(" ".join(map(str, arr)))

if __name__ == "__main__":
    seed = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    generate(seed)
TEMPLATE
}

template_stress() {
    cat <<'TEMPLATE'
#!/usr/bin/env bash
set -euo pipefail

# Config
readonly A_CPP="a.cpp"
readonly BRUTE_CPP="brute.cpp"
readonly GEN_PY="gen.py"
readonly TIMEOUT="2s"
readonly FLAGS="-std=c++17 -O2 -Wall"

# Colors
readonly C_OFF='\e[0m'
readonly C_OK='\e[32m'
readonly C_ERR='\e[31m'
readonly C_WARN='\e[33m'
readonly C_INFO='\e[36m'

cleanup() { rm -f int out1 out2; }
trap cleanup EXIT

echo -e "${C_INFO}[COMPILE] $A_CPP${C_OFF}"
g++ $FLAGS "$A_CPP" -o a.exe || exit 1

echo -e "${C_INFO}[COMPILE] $BRUTE_CPP${C_OFF}"
g++ $FLAGS "$BRUTE_CPP" -o brute.exe || exit 1

echo -e "${C_INFO}[TEST] Starting stress test...${C_OFF}\n"

for ((i=1; ; i++)); do
    echo -n "Test #$i: "
    
    python3 "$GEN_PY" "$i" > int
    
    if ! timeout "$TIMEOUT" ./a.exe < int > out1 2>/dev/null; then
        echo -e "${C_ERR}TLE (a.exe)${C_OFF}"
        break
    fi
    
    if ! timeout "$TIMEOUT" ./brute.exe < int > out2 2>/dev/null; then
        echo -e "${C_ERR}TLE (brute.exe)${C_OFF}"
        break
    fi
    
    if diff -w out1 out2 >/dev/null 2>&1; then
        echo -e "${C_OK}OK${C_OFF}"
    else
        echo -e "${C_ERR}WA${C_OFF}"
        echo -e "\n${C_WARN}=== INPUT ===${C_OFF}"
        cat int
        echo -e "\n${C_WARN}=== OUTPUT (a.exe) ===${C_OFF}"
        cat out1
        echo -e "\n${C_WARN}=== EXPECTED (brute.exe) ===${C_OFF}"
        cat out2
        break
    fi
done
TEMPLATE
}

template_gitignore() {
    cat <<'TEMPLATE'
# Binaries
*.exe
*.o
*.out
*.a
*.so

# Test files
int
out1
out2

# IDE
.vscode/
.idea/
*.swp

# System
.DS_Store
Thumbs.db
TEMPLATE
}

# ============================================================================
# MAIN LOGIC
# ============================================================================

main() {
    header_main
    
    # ────────────────────────────────────────────────────────────────────────
    # STEP 1: Select base directory
    # ────────────────────────────────────────────────────────────────────────
    header_step "1" "4" "BASE DIRECTORY" "Select project location"
    
    local -a valid_dirs=()
    for dir in "${BASE_DIRS[@]}"; do
        check_dir "$dir" && valid_dirs+=("$dir")
    done
    
    [[ ${#valid_dirs[@]} -eq 0 ]] && fatal "No valid base directories found"
    
    local base_dir=""
    if [[ ${#valid_dirs[@]} -eq 1 ]]; then
        base_dir="${valid_dirs[0]}"
        log_msg "Using: $base_dir"
    else
        PS3="$(echo -e "${CLR_CYAN}│ >${CLR_OFF} Select: ")"
        select base_dir in "${valid_dirs[@]}"; do
            [[ -n "$base_dir" ]] && break
            log_warn "Invalid choice"
        done
    fi
    
    log_ok "Base: $base_dir"
    footer_step
    
    # ────────────────────────────────────────────────────────────────────────
    # STEP 2: Project name
    # ────────────────────────────────────────────────────────────────────────
    header_step "2" "4" "PROJECT NAME" "Enter folder name"
    
    local project_name=""
    local target_dir=""
    
    while true; do
        read -r -p "$(echo -e "${CLR_CYAN}│ >${CLR_OFF} Name: ")" name_raw
        project_name="$(trim "$name_raw")"
        
        [[ -z "$project_name" ]] && { log_warn "Name cannot be empty"; continue; }
        has_forbidden "$project_name" && { log_warn "Invalid characters"; continue; }
        
        target_dir="$base_dir/$project_name"
        
        if [[ -e "$target_dir" ]]; then
            log_warn "Directory exists: $target_dir"
            ask_yn "Use existing?" "n" && { log_msg "Using existing"; break; }
            continue
        fi
        
        mkdir -p "$target_dir" 2>/dev/null || fatal "Cannot create: $target_dir"
        break
    done
    
    log_ok "Path: $target_dir"
    footer_step
    
    # ────────────────────────────────────────────────────────────────────────
    # STEP 3: Generate files
    # ────────────────────────────────────────────────────────────────────────
    header_step "3" "4" "FILES" "Creating project structure"
    
    template_cpp_multi > "$target_dir/a.cpp"
    log_msg "a.cpp"
    
    template_cpp_multi > "$target_dir/brute.cpp"
    log_msg "brute.cpp"
    
    template_cpp_single > "$target_dir/main.cpp"
    log_msg "main.cpp"
    
    template_generator > "$target_dir/gen.py"
    log_msg "gen.py"
    
    template_stress > "$target_dir/s.sh"
    log_msg "s.sh"
    
    template_gitignore > "$target_dir/.gitignore"
    log_msg ".gitignore"
    
    footer_step
    
    # ────────────────────────────────────────────────────────────────────────
    # STEP 4: Configuration
    # ────────────────────────────────────────────────────────────────────────
    header_step "4" "4" "CONFIG" "Setting permissions"
    
    command -v dos2unix &>/dev/null && {
        log_msg "Converting line endings..."
        dos2unix "$target_dir"/* 2>/dev/null || true
    }
    
    chmod +x "$target_dir/s.sh" "$target_dir/gen.py" 2>/dev/null || true
    log_msg "Executable permissions set"
    
    footer_step
    
    # ────────────────────────────────────────────────────────────────────────
    # Summary
    # ────────────────────────────────────────────────────────────────────────
    echo -e "${CLR_GREEN}┌────────────────────────────────────────────────┐${CLR_OFF}"
    echo -e "${CLR_GREEN}│${CLR_OFF} ${CLR_BOLD}${CLR_GREEN}SUCCESS${CLR_OFF} - Project created                      ${CLR_GREEN}│${CLR_OFF}"
    echo -e "${CLR_GREEN}└────────────────────────────────────────────────┘${CLR_OFF}\n"
    
    echo -e "${CLR_BOLD}Location:${CLR_OFF} ${CLR_CYAN}$target_dir${CLR_OFF}\n"
    echo -e "${CLR_BOLD}Files:${CLR_OFF}"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} a.cpp       Main solution (multi test)"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} brute.cpp   Brute force (multi test)"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} main.cpp    Quick test (single)"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} gen.py      Test generator"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} s.sh        Stress tester"
    echo -e "  ${CLR_YELLOW}→${CLR_OFF} .gitignore  Git config\n"
    
    # ────────────────────────────────────────────────────────────────────────
    # Optional: Open in VS Code
    # ────────────────────────────────────────────────────────────────────────
    if command -v code &>/dev/null; then
        ask_yn "Open in VS Code?" "y" && {
            log_msg "Launching VS Code..."
            code "$target_dir"
        }
    fi
    
    echo -e "\n${CLR_GREEN}${CLR_BOLD}>> Ready to code${CLR_OFF}\n"
}

# ============================================================================
# RUN
# ============================================================================

main "$@"