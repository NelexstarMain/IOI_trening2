#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int& x : arr) {
        std::cin >> x;
    }

    std::vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int m;
    std::cin >> m;

    std::vector<int> etic(m);
    for(int& x : etic) {
        std::cin >> x;
    }

    for (int i = 0; i < m; ++i) {
        int num = etic[i];
        int l = 0, r = n - 1;
        int result_index = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (prefix[mid] >= num) {
                result_index = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        std::cout << result_index + 1 << "\n";
    }

    return 0;
}