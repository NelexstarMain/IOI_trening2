#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int test_cases;
    std::cin >> test_cases;
    while (test_cases--) {
        int n;
        std::cin >> n;
        std::vector<int> b(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            std::cin >> b[i];
        }
        std::sort(b.begin(), b.end());

        std::vector<long long> a(2 * n + 1);

        // Assign even-indexed elements of 'a' with the larger half of 'b'
        for (int i = 0; i <= n; ++i) {
            a[2 * i] = b[n + i - 1];
        }

        // Assign odd-indexed elements of 'a' with the smaller half of 'b'
        for (int i = 0; i < n - 1; ++i) {
            a[2 * i + 1] = b[i];
        }
        
        long long sum_large = 0;
        for (int i = n - 1; i < 2 * n; ++i) {
            sum_large += b[i];
        }

        long long sum_small = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum_small += b[i];
        }

        a[2 * n - 1] = sum_large - sum_small;

        for (int i = 0; i < 2 * n + 1; ++i) {
            std::cout << a[i] << (i == 2 * n ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}