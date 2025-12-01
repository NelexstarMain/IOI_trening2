#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::vector<int> counts(n + 2, 0);
    long long initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] < n + 2) {
            counts[a[i]]++;
        }
        initial_sum += a[i];
    }

    // Jeśli k=0, nic się nie zmienia (zgodnie z ograniczeniami k>=1, ale dla kompletności)
    if (k == 0) {
        std::cout << initial_sum << std::endl;
        return;
    }

    // Krok 1: Symulacja pierwszej operacji
    int m = 0;
    while (m < n + 2 && counts[m] > 0) {
        m++;
    }

    std::vector<bool> in_U(m + 1, false);
    long long sum_U = 0;
    int size_U = 0;
    for (int i = 0; i < m; ++i) {
        if (counts[i] == 1) {
            in_U[i] = true;
            sum_U += i;
            size_U++;
        }
    }

    long long c = n - size_U;
    long long sum_after_1_op = sum_U + c * m;

    if (k == 1) {
        std::cout << sum_after_1_op << std::endl;
        return;
    }

    // Krok 2: Sprawdzenie stabilizacji (czy a^(1) jest permutacją 0..n-1)
    int mex_U = 0;
    while (mex_U < m + 1 && in_U[mex_U]) {
        mex_U++;
    }

    if (c == 1 && mex_U == m) {
        // Tablica staje się permutacją 0..n-1, więc jest stabilna
        std::cout << sum_after_1_op << std::endl;
        return;
    }

    // Krok 3: Logika cyklu dla k > 1
    int g = mex_U;
    
    // Oblicz h = MEX(U U {g})
    int h = g + 1;
    // Potrzebujemy większego wektora bool, aby bezpiecznie znaleźć h
    // Najbezpieczniej jest stworzyć nowy na podstawie counts
    std::vector<bool> is_in_U_full(n + 2, false);
    for(int i=0; i<m; ++i) {
        if (counts[i] == 1) {
            is_in_U_full[i] = true;
        }
    }
    while(h < n + 2 && is_in_U_full[h]) {
        h++;
    }


    long long v1 = m;
    long long v2 = (v1 != g) ? g : h;
    long long v3 = (v2 == g) ? h : g;

    long long final_v;
    if (k % 2 == 0) { // k jest parzyste
        final_v = v2;
    } else { // k jest nieparzyste
        final_v = v3;
    }

    long long final_sum = sum_U + c * final_v;
    std::cout << final_sum << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}