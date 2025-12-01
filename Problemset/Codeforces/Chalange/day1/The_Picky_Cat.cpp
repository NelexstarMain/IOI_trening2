#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; 
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);

        for (int &x : a)
            std::cin >> x;

        std::vector<std::pair<int,int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.emplace_back(std::abs(a[i]), i);
        }
        std::sort(pairs.begin(), pairs.end());

        std::vector<int> ans(n, 0);
        int limit = n / 2 + 1;
        for (int i = 0; i < limit; i++) {
            ans[pairs[i].second] = 1;
        }

        if (ans[0] == 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
