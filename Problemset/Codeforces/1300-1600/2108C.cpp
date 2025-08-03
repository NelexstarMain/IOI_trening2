#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int& x : arr) std::cin >> x;

        std::vector<int> compressed;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && arr[j] == arr[i]) j++;
            compressed.push_back(arr[i]);
            i = j;
        }

        int m = compressed.size();
        int count = 0;

        if (m >= 2 && compressed[0] > compressed[1])
            count++;

        for (int i = 1; i + 1 < m; ++i) {
            if (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) {
                count++;
            }
        }

        if (m >= 2 && compressed[m - 1] > compressed[m - 2])
            count++;

        std::cout << (count > 0 ? count : 1) << '\n';
    }
}
