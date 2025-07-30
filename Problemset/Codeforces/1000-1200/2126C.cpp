#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T; std::cin >> T;
    while (T--) {
        int n, m; std::cin >> n >> m;
        std::vector<int> arr(n);
        for (int& x : arr) std::cin >> x;

        std::vector<int> b = arr;
        std::sort(b.begin(), b.end());

        int d = arr[m - 1];

        int idx = std::find(arr.rbegin(), arr.rend(), arr[m - 1]) - arr.rbegin();
        idx = arr.size() - 1 - idx;

        auto it = std::find(b.begin(), b.end(), arr[m - 1]);
        int sorted_idx = it - b.begin();

        bool ok = true;
        for (int i = sorted_idx; i < n; i++) {
            if (b[i] - b[sorted_idx] > d) {
                ok = false;
                break;
            } 
            sorted_idx = i;
        }

        std::cout << (ok ? "YES\n" : "NO\n");
    }
}
