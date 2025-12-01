#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, std::vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        positions[a[i]].push_back(i + 1);
    }

    std::vector<long long> dp(n + 1, 0);
    std::vector<long long> M(n + 1, 0);
    std::map<int, int> counts;

    for (int i = 1; i <= n; ++i) {
        int val = a[i - 1];
        counts[val]++;
        int k = counts[val];

        if (k >= val) {
            int start_occurrence_idx = k - val;
            int j = positions[val][start_occurrence_idx];
            long long prev_max = (j > 1) ? M[j - 1] : 0;
            dp[i] = prev_max + val;
        }

        M[i] = std::max(M[i - 1], dp[i]);
    }

    std::cout << M[n] << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}