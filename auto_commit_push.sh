#!/bin/bash
set -e 

echo "🌳 Aktualizowanie struktury folderu CP4..."
OUTPUT_FILE="CP4_STRUCTURE.md"

cat << 'EOF' > "$OUTPUT_FILE"
# CP4

<div style="font-family: monospace; line-height: 1.5;">

<b>📂 CP4</b><br>
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
        
        local branch="├── "
        [ "$index" -eq "$count" ] && branch="└── "
        
        # Tworzymy wcięcie za pomocą spacji niełamiących (HTML)
        local indent="${prefix}${branch}"
        
        if [ -d "$item" ]; then
            echo "${indent}📂 <b>${base_name}</b><br>" >> "$OUTPUT_FILE"
            generate_tree_html "$item" "${prefix}&nbsp;&nbsp;&nbsp;&nbsp;"
        else
            local icon="📝"
            local color="gray"
            if [[ "$base_name" == *.cpp ]]; then icon="🔵"; color="blue"; fi
            if [[ "$base_name" == *.py ]]; then icon="🟡"; color="gold"; fi
            
            echo "${indent}${icon} <span style=\"color:${color}\">${base_name}</span><br>" >> "$OUTPUT_FILE"
        fi
    done
}

generate_tree_html "CP4" ""
echo "</div>" >> "$OUTPUT_FILE"

echo "✅ Zaktualizowano!"

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