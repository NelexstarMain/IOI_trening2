
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_set<int> possible_targets_set;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        

        while (true) {
            if (possible_targets_set.count(x)) {
                break;
            }
            possible_targets_set.insert(x);
            if (x == 0) {
                break;
            }
            x /= 2;
        }

    int ans = 1e9;
    for (int res : possible_targets_set) {
        std::vector<int> cnt;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int cur_ops = 0;
            while (x > res) {
                x /= 2;
                ++cur_ops;
            }
            if (x == res) {
                cnt.push_back(cur_ops);
            }
        }

        if (cnt.size() >= k) {
            std::sort(cnt.begin(), cnt.end());
            ans = std::min(ans, std::accumulate(cnt.begin(), cnt.begin() + k, 0));
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
