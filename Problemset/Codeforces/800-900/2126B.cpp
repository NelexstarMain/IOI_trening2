#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> arr(n);
        for (int& x : arr) std::cin >> x;

        int i = 0;
        int count = 0;

        while (i + m <= n) {
            if (std::all_of(arr.begin() + i, arr.begin() + i + m, [](int x) {
                return x == 0;
            })) {
                i += m + 1;
                count++;
            } else {
                i++;
            }
        }

        std::cout << count << '\n';
    }
}
