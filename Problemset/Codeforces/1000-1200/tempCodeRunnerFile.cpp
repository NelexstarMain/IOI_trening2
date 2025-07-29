#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) {
        int n; std::cin >> n;
        std::vector<int> arr(n);
        std::string res;

        for (int& x: arr) std::cin >> x;
        int mi = std::min_element(arr.begin(), arr.end()) - arr.begin();
        int ma = std::max_element(arr.begin(), arr.end()) - arr.begin();
        int left = std::min(mi, ma);
        int right = std::max(mi, ma);
        for (int i = 0; i < n; i++) {
            if (i != mi && i != ma) {
                if (i < left || i > right)
                    res += '1';
                else
                    res += '0';
            } else {
                res += '1';
            }
        }
        std::cout << res << std::endl;
    }
}