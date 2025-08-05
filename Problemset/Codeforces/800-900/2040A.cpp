#include <iostream>
#include <vector>
#include <cmath>

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int& x : arr) std::cin >> x;

    for (int i = 0; i < n; i++) {
        bool canWin = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;  
            if (std::abs(arr[i] - arr[j]) % k == 0) {
                canWin = false;
                break;
            }
        }
        if (canWin) {
            std::cout << "YES\n" << i + 1 << "\n";
            return;
        }
    }
    std::cout << "NO\n";
}

int main() {
    int T; std::cin >> T;
    while (T--) solve();
}
