#!/bin/bash
set -e 

# ==========================================
# 1. GENEROWANIE DRZEWA TYLKO DLA FOLDERU CP4
# ==========================================
echo "🌳 Aktualizowanie struktury folderu CP4..."

# Tworzymy nagłówek pliku Markdown
cat << 'EOF' > CP4_STRUCTURE.md
# 📖 Struktura zadań - Competitive Programming 4 (CP4)

Poniżej znajduje się aktualne, automatycznie generowane drzewo rozwiązanych zadań przypisanych do poszczególnych rozdziałów książki CP4:

```text
EOF

# Próba użycia komendy tree (sortuje foldery na samej górze)
if command -v tree &> /dev/null; then
    tree CP4 --dirsfirst >> CP4_STRUCTURE.md
else
    # Automatyczny fallback (zastępstwo) jeśli nie masz 'tree' na Windowsie
    # Rysuje ładne drzewo za pomocą wbudowanych narzędzi Git Bash
    find CP4 | sort | awk -F'/' '{
        depth = NF - 1;
        if (depth == 0) { print $1; }
        else {
            prefix = "";
            for (i = 1; i < depth; i++) { prefix = prefix "│   "; }
            print prefix "├── " $NF;
        }
    }' >> CP4_STRUCTURE.md
fi

# Zamykamy blok kodu Markdown
echo '```' >> CP4_STRUCTURE.md
echo "✅ Zaktualizowano CP4_STRUCTURE.md"
# ==========================================

RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START ---"
git add -A

if [ -z "$(git status --porcelain)" ]; then
    echo "⚠️ Brak zmian do zatwierdzenia. Kończę."
    exit 0
fi

echo "$RANDOM_STRING"
git commit -m "$RANDOM_STRING"

echo "(Pull)..."
git pull --rebase --autostash

echo "(Push)..."
git push -u origin HEAD

echo "--- READY ---"