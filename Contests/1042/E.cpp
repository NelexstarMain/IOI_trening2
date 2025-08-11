#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Funkcja do rozwiązania pojedynczego przypadku testowego
void solve() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // Warunek 1: Ostatnie elementy muszą być takie same.
    // Używamy indeksowania od 0, więc jest to n-1.
    if (a[n - 1] != b[n - 1]) {
        std::cout << "NO\n";
        return;
    }

    // Warunek 2: Porównanie multizbiorów sum prefiksowych XOR.
    // Aby porównać multizbiory, tworzymy wektory, sortujemy je i porównujemy.
    
    std::vector<long long> prefix_a, prefix_b;
    
    // Wstawiamy 0 dla pustego prefiksu
    prefix_a.push_back(0);
    prefix_b.push_back(0);

    long long current_xor_a = 0;
    long long current_xor_b = 0;

    // Obliczamy sumy prefiksowe dla obu tablic
    // Pomijamy ostatni element, ponieważ a[n-1] i b[n-1] muszą być równe,
    // a co za tym idzie, ostateczne sumy XOR również będą równe.
    // Uwzględnienie ich nie zmieni wyniku, ale można je pominąć dla optymalizacji.
    for (int i = 0; i < n - 1; ++i) {
        current_xor_a ^= a[i];
        prefix_a.push_back(current_xor_a);

        current_xor_b ^= b[i];
        prefix_b.push_back(current_xor_b);
    }
    
    // Sortujemy wektory, aby móc je porównać jako multizbiory
    std::sort(prefix_a.begin(), prefix_a.end());
    std::sort(prefix_b.begin(), prefix_b.end());

    // Jeśli posortowane wektory są takie same, multizbiory też są
    if (prefix_a == prefix_b) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Przyspieszenie operacji wejścia/wyjścia
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}