#include <bits/stdc++.h>


void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

void solve() {
    int n; std::cin >> n;
    int res = 0;
    std::vector<int> arr(n); for (int& x: arr) {
        std::cin >> x;
        if (x == 0) {
            res++;
        } else {
            res += x;
        }
    };
    std::cout << res << "\n";
}

int main() {
    fast_io();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}