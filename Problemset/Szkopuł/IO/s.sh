#!/bin/bash

SOLVER_FILE="przeglondarka.cpp"
BRUTE_FILE="brute.cpp"
GENERATOR_FILE="gen.cpp"
SOLVER_EXEC="prz_opt"
BRUTE_EXEC="prz_brute"
GEN_EXEC="gen"

NUM_TESTS=100

echo "⚙️ Kompilacja..."

g++ -std=c++17 -O2 "$SOLVER_FILE" -o "$SOLVER_EXEC" || { echo "❌ Blad kompilacji $SOLVER_FILE"; exit 1; }
g++ -std=c++17 -O2 "$BRUTE_FILE" -o "$BRUTE_EXEC" || { echo "❌ Blad kompilacji $BRUTE_FILE"; exit 1; }
g++ -std=c++17 -O2 "$GENERATOR_FILE" -o "$GEN_EXEC" || { echo "❌ Blad kompilacji $GENERATOR_FILE"; exit 1; }

echo "✅ Kompilacja zakonczona sukcesem."
echo "---"

echo "🚀 Uruchamianie $NUM_TESTS testow (weryfikacja dla N<=8)..."

ERRORS=0

for i in $(seq 1 $NUM_TESTS); do
    TEST_NAME="test_$i"
    INPUT_FILE="${TEST_NAME}.in"
    SOLVER_OUTPUT="${TEST_NAME}.out"
    BRUTE_OUTPUT="${TEST_NAME}.brute.out"
    
    N_PARAM=$(( RANDOM % 2000 + 5 ))
    S_PARAM=$(( N_PARAM * (RANDOM % 50 + 5)))
    echo "  -> Generowanie: $TEST_NAME (N=$N_PARAM, S=$S_PARAM)..."
    ./"$GEN_EXEC" $N_PARAM $S_PARAM > "$INPUT_FILE"

    ./"$SOLVER_EXEC" < "$INPUT_FILE" > "$SOLVER_OUTPUT"
    ./"$BRUTE_EXEC" < "$INPUT_FILE" > "$BRUTE_OUTPUT"

    SOLVER_COST=$(head -n 1 "$SOLVER_OUTPUT" | tr -d '\r')
    BRUTE_COST=$(head -n 1 "$BRUTE_OUTPUT" | tr -d '\r')

    if ! [[ "$SOLVER_COST" =~ ^[0-9]+$ ]] || ! [[ "$BRUTE_COST" =~ ^[0-9]+$ ]]; then
        echo "  ❌ $TEST_NAME: BŁĄD WYJŚCIA!"
        echo "     Optymalne='${SOLVER_COST}', Brute='${BRUTE_COST}'"
        ((ERRORS++))
        continue
    fi
    
    if [ "$SOLVER_COST" -eq "$BRUTE_COST" ]; then
        echo "  ✔️ $TEST_NAME: KOSZT ZGODNY (Koszt: $SOLVER_COST)"
    else
        echo "  ❌ $TEST_NAME: KOSZT NIEZGODNY!"
        echo "     Twoje:  $SOLVER_COST"
        echo "     Brute:  $BRUTE_COST"
        echo "     Dane:   $INPUT_FILE"
        ((ERRORS++))
    fi
done

echo "---"
echo "🎉 Testy zakonczone."
echo "   Bledy: $ERRORS / $NUM_TESTS"

if [ "$ERRORS" -gt 0 ]; then
    echo "⚠️  Są niezgodne testy — sprawdź pliki wejściowe powyżej."
else
    echo "✅ Wszystkie testy poprawne!"
fi
