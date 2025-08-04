#include <iostream>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int n, m, p, q; std::cin >> n >> m >> p >> q;
        if (n%p == 0 && (n/p)*q != m) {
            std::cout << "No\n";
        } else {
            std::cout << "YES\n";
        }

    }
}