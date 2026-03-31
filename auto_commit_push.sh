#!/bin/bash
set -e 

# =========================================================
# 1. GENEROWANIE KOLOROWEGO DRZEWA Z KRESKAMI (MARKDOWN)
# =========================================================
echo "🌳 Aktualizowanie struktury folderu CP4..."

OUTPUT_FILE="CP4_STRUCTURE.md"

# Tworzymy ładny nagłówek z legendą
cat << 'EOF' > "$OUTPUT_FILE"

📂 **Folder** | 🔵 C++ | 🟡 Python | 📝 Other

<pre>
EOF

# Funkcja rekurencyjna
generate_tree() {
    local dir="$1"
    local prefix="$2"
    
    # Bezpieczne pobieranie plików
    local items=()
    for item in "$dir"/*; do
        [ -e "$item" ] && items+=("$item")
    done
    
    local count=${#items[@]}
    [ "$count" -eq 0 ] && return
    
    local index=0
    for item in "${items[@]}"; do
        # Poprawka: to wyrażenie nie wywali skryptu przy set -e
        index=$((index + 1))
        
        local base_name=$(basename "$item")
        
        # Ignoruj pliki systemowe/ukryte
        [[ "$base_name" == .* ]] && continue
        
        local is_last=0
        [ "$index" -eq "$count" ] && is_last=1
        
        local branch="├──"
        local next_prefix="│   "
        if [ "$is_last" -eq 1 ]; then
            branch="└──"
            next_prefix="    "
        fi
        
        if [ -d "$item" ]; then
            echo "${prefix}${branch} 📂 **${base_name}**  " >> "$OUTPUT_FILE"
            generate_tree "$item" "${prefix}${next_prefix}"
        elif [ -f "$item" ]; then
            if [[ "$base_name" == *.cpp ]]; then
                echo "${prefix}${branch} 🔵 \`${base_name}\`  " >> "$OUTPUT_FILE"
            elif [[ "$base_name" == *.py ]]; then
                echo "${prefix}${branch} 🟡 \`${base_name}\`  " >> "$OUTPUT_FILE"
            else
                echo "${prefix}${branch} 📝 \`${base_name}\`  " >> "$OUTPUT_FILE"
            fi
        fi
    done
}

if [ -d "CP4" ]; then
    echo "📂 **CP4**  " >> "$OUTPUT_FILE"
    generate_tree "CP4" ""
    echo "✅ Zaktualizowano $OUTPUT_FILE!"
else
    echo "❌ Błąd: Folder CP4 nie istnieje w tym miejscu!"
fi
echo "</pre>" >> "$OUTPUT_FILE"
# =========================================================

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