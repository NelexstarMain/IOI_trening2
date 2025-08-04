#include <iostream>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        for (int i = 0; i < k; i++) {
            std::cout << "1";
        }
        for (int i = 0; i < (n-k); i++) {
            std::cout << "0";
        }
        std::cout << '\n';
    }
}