#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string a_global, b_global;
int min_global;

void dp(int i, bool tight_l, bool tight_r, int current_sum) {
    if (i == a_global.size()) {
        min_global = std::min(min_global, current_sum);
        return;
    }

    if (current_sum >= min_global) {
        return;
    }

    int d_min = tight_l ? (a_global[i] - '0') : 0;
    int d_max = tight_r ? (b_global[i] - '0') : 9;

    for (int d = d_min; d <= d_max; ++d) {
        int cost = 0;
        if ((a_global[i] - '0') == d) {
            cost++;
        }
        if ((b_global[i] - '0') == d) {
            cost++;
        }

        bool new_tight_l = tight_l && (d == d_min);
        bool new_tight_r = tight_r && (d == d_max);

        dp(i + 1, new_tight_l, new_tight_r, current_sum + cost);
    }
}

void solve() {
    std::cin >> a_global >> b_global;

    if (a_global == b_global) {
        std::cout << a_global.size() * 2 << std::endl;
        return;
    }

    min_global = INT_MAX;
    dp(0, true, true, 0);
    std::cout << min_global << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}