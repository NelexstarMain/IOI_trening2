#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    if (n > 2) {
        for (int i = 0; i < n; ++i) {
            // Sprawdzenie, czy jesteśmy na ostatnim elemencie
            if (i == n - 1 && n % 2 == 0) {
                std::cout << 2 << " ";
            } else if (i % 2 == 0) {
                std::cout << -1 << " ";
            } else {
                std::cout << 3 << " ";
            }
        }
    } else {
        std::cout << -1 << " " << 2;
    }
    std::cout << "\n";
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