#!/bin/bash
set -e 

# Zabezpieczenie przed błędami, gdy folder jest pusty
shopt -s nullglob

echo "📟 Aktualizowanie struktury folderu CP4 w stylu Retro HTML..."
OUTPUT_FILE="CP4_STRUCTURE.md"
TARGET_DIR="CP4"

# --- LICZENIE STATYSTYK CAŁKOWITYCH ---
# -iname ignoruje wielkość liter (złapie Kattis, uva, UVa, KATTIS)
TOTAL_KATTIS=$(find "$TARGET_DIR" -type d -iname "kattis" -exec find {} -type f ! -name ".*" \; 2>/dev/null | wc -l | xargs)
TOTAL_UVA=$(find "$TARGET_DIR" -type d -iname "uva" -exec find {} -type f ! -name ".*" \; 2>/dev/null | wc -l | xargs)
TOTAL_SUM=$((TOTAL_KATTIS + TOTAL_UVA))

cat << 'EOF' > "$OUTPUT_FILE"
<div style="background-color: #050505; color: #00ff00; padding: 20px; font-family: 'Courier New', Courier, monospace; border: 2px solid #00ff00; border-radius: 5px; box-shadow: 0 0 10px rgba(0, 255, 0, 0.4); line-height: 1.4;">
<div style="white-space: pre; color: #00ff00; font-weight: bold; margin-bottom: 20px;">
  _   _   _   _  
 / \ / \ / \ / \ 
( C | P | 4 | )
 \_/ \_/ \_/ \_/[ UNIT: ROOT_DIRECTORY ]
 [ ACCESS: GRANTED ]
</div>
<hr style="border: 0; border-top: 1px dashed #00ff00; margin: 15px 0;">
<b>[DIR] CP4</b><br>
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
        
        # Ignoruj pliki ukryte (zaczynające się od kropki)
        [[ "$base_name" == .* ]] && continue
        
        local branch="├── "
        [ "$index" -eq "$count" ] && branch="└── "
        
        local indent="${prefix}${branch}"
        
        if [ -d "$item" ]; then
            local folder_info=""
            # Konwersja na małe litery, by łatwo sprawdzić nazwę
            local lower_name=$(echo "$base_name" | tr '[:upper:]' '[:lower:]')
            
            if [[ "$lower_name" == "kattis" || "$lower_name" == "uva" ]]; then
                # Szukamy plików wewnątrz tego konkretnego folderu
                local sub_count=$(find "$item" -type f ! -name ".*" | wc -l | xargs)
                folder_info=" <span style='color: #ffffff; text-shadow: 0 0 5px #fff;'>[FILES: ${sub_count}]</span>"
            fi
            
            echo "${indent}<span style='color: #00ff00;'>[DIR]</span> <b>${base_name}</b>${folder_info}<br>" >> "$OUTPUT_FILE"
            generate_tree_html "$item" "${prefix}&nbsp;&nbsp;&nbsp;&nbsp;"
        else
            local ext="[FILE]"
            if [[ "$base_name" == *.cpp ]]; then ext="[CPP]"; fi
            if [[ "$base_name" == *.py ]]; then ext="[PY_]"; fi
            
            echo "${indent}<span style='color: #00aa00;'>${ext}</span> <span style='color: #00aa00;'>${base_name}</span><br>" >> "$OUTPUT_FILE"
        fi
    done
}

generate_tree_html "$TARGET_DIR" ""

# Dopisywanie podsumowania na dole
cat << EOF >> "$OUTPUT_FILE"
<hr style="border: 0; border-top: 1px dashed #00ff00; margin: 15px 0;">
<div style="white-space: pre; color: #00ff00; font-weight: bold;">
&gt;&gt; DATABASE SUMMARY
&gt;&gt; ---------------------------
&gt;&gt; KATTIS_ENTRIES: $TOTAL_KATTIS
&gt;&gt; UVA_ENTRIES:    $TOTAL_UVA
&gt;&gt; ---------------------------
&gt;&gt; TOTAL_RECORDS:  $TOTAL_SUM
&gt;&gt; ---------------------------
&gt;&gt; STATUS: ALL_FILES_SYNCED
</div>
<div style="text-align: center; font-size: 0.8em; margin-top: 20px; letter-spacing: 2px;">
--- END OF DATA TRANSMISSION ---
</div>
</div>
EOF

echo "✅ Zaktualizowano strukturę MD!"

# --- GIT OPERATIONS ---
RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START ---"
git add -A

if [ -z "$(git status --porcelain)" ]; then
    echo "⚠️ Brak zmian do zatwierdzenia. Kończę."
    exit 0
fi

echo "Generowanie commitu: $RANDOM_STRING"
git commit -m "$RANDOM_STRING"

echo "(Pull)..."
git pull --rebase --autostash

echo "(Push)..."
git push -u origin HEAD

echo "--- READY ---"