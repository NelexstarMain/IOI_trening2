#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n); for (int& x: a) std::cin >> x;
    int sum = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        sum += a[i]*std::max(0, m-i+1);
    }
    std::cout << sum << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}