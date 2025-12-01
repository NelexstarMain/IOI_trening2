#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int& x : a) {
            std::cin >> x;
        }

        std::vector<int> c = a;
        std::sort(c.begin(), c.end());

        std::vector<int> derangement_candidate;
        for (int i = 0; i < n; i++) {
            if (a[i] != c[i]) {
                derangement_candidate.push_back(a[i]);
            }
        }

        if (derangement_candidate.empty()) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            std::cout << derangement_candidate.size() << "\n";
            for (int i = 0; i < derangement_candidate.size(); ++i) {
                std::cout << derangement_candidate[i] << (i == derangement_candidate.size() - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}