#!/bin/bash
set -e 
shopt -s nullglob

OUTPUT_FILE="CP4_STRUCTURE.md"
TARGET_DIR="CP4"

echo "📟 GENERATING RETRO SYSTEM REPORT..."
TOTAL_KATTIS=$(find "$TARGET_DIR" -type d -iname "kattis" -exec find {} -type f ! -name ".*" \; 2>/dev/null | wc -l | xargs)
TOTAL_UVA=$(find "$TARGET_DIR" -type d -iname "uva" -exec find {} -type f ! -name ".*" \; 2>/dev/null | wc -l | xargs)
TOTAL_SUM=$((TOTAL_KATTIS + TOTAL_UVA))
cat << EOF > "$OUTPUT_FILE"

<div style="background-color: #050505; color: #00ff00; padding: 15px; border: 1px solid #00ff00; font-family: monospace;">
<pre style="background: transparent; color: #00ff00; border: none; padding: 0; margin: 0; line-height: 1.2;">
  _   _   _   _  
 / \ / \ / \ / \ 
( C | P | 4 | )
 \_/ \_/ \_/ \_/ 

 [ UNIT: ROOT_SCANNER ]
 [ STATUS: GRANTED ]
 -------------------------------------------
EOF

generate_tree() {
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
        
        local branch="├── "
        local next_prefix="${prefix}│   "
        if [ "$index" -eq "$count" ]; then
            branch="└── "
            next_prefix="${prefix}    "
        fi
        
        if [ -d "$item" ]; then
            local folder_info=""
            local lower_name=$(echo "$base_name" | tr '[:upper:]' '[:lower:]')
            if [[ "$lower_name" == "kattis" || "$lower_name" == "uva" ]]; then
                local sub_count=$(find "$item" -type f ! -name ".*" | wc -l | xargs)
                folder_info=" [FILES: ${sub_count}]"
            fi
            echo "${prefix}${branch}[DIR] ${base_name}${folder_info}" >> "$OUTPUT_FILE"
            generate_tree "$item" "$next_prefix"
        else
            local type="[FILE]"
            if [[ "$base_name" == *.cpp ]]; then type="[CPP ]"; fi
            if [[ "$base_name" == *.py ]]; then type="[PY_ ]"; fi
            
            echo "${prefix}${branch}${type} ${base_name}" >> "$OUTPUT_FILE"
        fi
    done
}
echo "CP4" >> "$OUTPUT_FILE"
generate_tree "$TARGET_DIR" ""
cat << EOF >> "$OUTPUT_FILE"

 -------------------------------------------
 >> DATABASE SUMMARY
 >> KATTIS: $TOTAL_KATTIS
 >> UVA:    $TOTAL_UVA
 >> TOTAL:  $TOTAL_SUM
 >> STATUS: ALL_SYSTEMS_GO
 -------------------------------------------
 [ END OF TRANSMISSION ]
</pre>
</div>
EOF

echo "✅ Gotowe! Plik $OUTPUT_FILE został wygenerowany."
RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)
git add -A
if [ -z "$(git status --porcelain)" ]; then
    echo "⚠️ Brak zmian."
    exit 0
fi
git commit -m "update: $RANDOM_STRING"
git pull --rebase --autostash
git push -u origin HEAD