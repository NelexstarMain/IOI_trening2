#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int sq = sqrt(n);
        if (sq*sq != n) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << sq << " 0" << std::endl;
        }
    }
}
