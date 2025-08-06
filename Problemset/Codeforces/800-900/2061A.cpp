#include <iostream>
#include <vector>

void solve() {
    int n, odd = 0, even = 0; std::cin >> n;
    for (int i = 0; i<n; i++) {
        int x; std::cin >> x;
        if (x%2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    if (even > 0) {
        std::cout << odd+1;
    } else {
        std::cout << odd-1;
    }
    std::cout << "\n";

}

int main() {
    int T; std::cin >> T;
    while (T--) solve();
}