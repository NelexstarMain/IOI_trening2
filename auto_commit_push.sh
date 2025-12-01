#!/bin/bash

# Użycie 'set -e' powoduje, że skrypt zatrzymuje się natychmiast, gdy 
# jakakolwiek komenda zwróci błąd (status wyjścia != 0).
set -e 

# --- Generowanie Losowego Ciągu (15 znaków) ---
RANDOM_STRING=$(head /dev/urandom | tr -dc A-Za-z0-9 | head -c 15)

echo "--- START: Automatyczna synchronizacja (Commit -> Pull -> Push) ---"

# 1. Dodaj wszystkie pliki
echo "1. Dodawanie wszystkich plików (git add .)..."
git add .

# 2. Sprawdź, czy są zmiany do commitowania
# Jeśli nie ma zmian, kończy działanie skryptu
if git diff-index --quiet HEAD --; then
    echo "⚠️ Brak zmian do zatwierdzenia. Zakończono."
    exit 0
fi

# 3. Commit zmian
echo "2. Commitowanie wiadomością: $RANDOM_STRING"
git commit -m "$RANDOM_STRING"

# 4. PULL (Pobierz najnowsze zmiany z repozytorium)
# Używamy --rebase, aby utrzymać czystą historię, umieszczając nasz commit na wierzchu.
echo "3. Pobieranie zmian z repozytorium (git pull --rebase)..."
git pull --rebase

# UWAGA: Jeśli 'git pull --rebase' natrafi na poważny konflikt,
# skrypt zatrzyma się, a Ty będziesz musiał ręcznie rozwiązać konflikt w VS Code
# i uruchomić ponownie skrypt (lub dokończyć rebase ręcznie).

# 5. PUSH (Wyślij nasze zmiany)
echo "4. Wysyłanie zmian (git push)..."
git push

echo "✅ Wszystkie operacje Git zakończone pomyślnie."
echo "--- KONIEC ---"