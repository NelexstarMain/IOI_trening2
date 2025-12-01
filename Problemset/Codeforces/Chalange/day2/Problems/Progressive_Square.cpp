#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        int n, c, d;
        std::cin >> n >> c >> d;

        int total_elements = n * n;
        std::vector<int> b(total_elements);

        for (int& x : b) {
            std::cin >> x;
        }

        std::sort(b.begin(), b.end());

        long long a = b[0];

        std::vector<long long> generated_elements;
        generated_elements.reserve(total_elements);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                generated_elements.push_back(a + 1LL * i * c + 1LL * j * d);
            }
        }

        std::sort(generated_elements.begin(), generated_elements.end());

        bool valid = true;
        for (int i = 0; i < total_elements; ++i) {
            if (generated_elements[i] != b[i]) {
                valid = false;
                break;
            }
        }

        std::cout << (valid ? "YES" : "NO") << '\n';
    }

    return 0;
}