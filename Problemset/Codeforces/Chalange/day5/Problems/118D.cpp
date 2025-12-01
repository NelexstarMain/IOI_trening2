#include <iostream>
#include <vector>

const int MOD = 100000000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n1, n2, k1, k2;
    std::cin >> n1 >> n2 >> k1 >> k2;

    std::vector<std::vector<std::vector<int>>> dp(n1 + 1, std::vector<std::vector<int>>(n2 + 1, std::vector<int>(2, 0)));

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            for (int last_footmen_len = 1; last_footmen_len <= k1; ++last_footmen_len) {
                if (i - last_footmen_len >= 0) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - last_footmen_len][j][1]) % MOD;
                }
            }

            for (int last_horsemen_len = 1; last_horsemen_len <= k2; ++last_horsemen_len) {
                if (j - last_horsemen_len >= 0) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - last_horsemen_len][0]) % MOD;
                }
            }
        }
    }

    std::cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << std::endl;

    return 0;
}    