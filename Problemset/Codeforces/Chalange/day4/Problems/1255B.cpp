#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int q;
    std::cin >> q;
    
    while (q--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> arr(n);
        for (int& x : arr) std::cin >> x;

        if (m < n || n == 2) {
            std::cout << -1 << '\n';
            continue;
        }

        std::vector<std::vector<int>> res;
        long long price = 0;

        // Tworzymy cykl
        for (int i = 0; i < n; ++i) {
            int a = i;
            int b = (i + 1) % n;
            res.push_back({a + 1, b + 1});  // 1-indeksowo
            price += arr[a] + arr[b];
        }

        // Dodatkowe krawędzie, jeśli m > n
        if (m > n) {
            int extra = m - n;

            std::vector<std::pair<int, int>> with_index;
            for (int i = 0; i < n; ++i)
                with_index.push_back({arr[i], i});

            std::sort(with_index.begin(), with_index.end());
            int idx1 = with_index[0].second;
            int idx2 = with_index[1].second;

            for (int i = 0; i < extra; ++i) {
                res.push_back({idx1 + 1, idx2 + 1});
                price += arr[idx1] + arr[idx2];
            }
        }

        std::cout << price << '\n';
        for (auto& edge : res) {
            std::cout << edge[0] << " " << edge[1] << '\n';
        }
    }
}
