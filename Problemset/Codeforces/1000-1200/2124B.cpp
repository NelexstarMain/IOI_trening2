#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (int& x: arr) std::cin >> x;
    std::cout << std::min((arr[0]+arr[1]), arr[0]*2) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
}