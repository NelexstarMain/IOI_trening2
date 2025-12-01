#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int target_gcd = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i == 0) {
            target_gcd = a[i];
        } else {
            target_gcd = gcd(target_gcd, a[i]);
        }
    }

    if (n == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    int count_target = 0;
    for (int x : a) {
        if (x == target_gcd) {
            count_target++;
        }
    }

    if (count_target > 0) {
        std::cout << n - count_target << std::endl;
        return;
    }

    std::set<int> unique_a_set(a.begin(), a.end());
    std::vector<int> unique_a(unique_a_set.begin(), unique_a_set.end());

    std::queue<std::pair<int, int>> q;
    std::map<int, int> min_ops;

    for (int x : unique_a) {
        if (min_ops.find(x) == min_ops.end()) {
            q.push({x, 0});
            min_ops[x] = 0;
        }
    }

    int k_create = -1;
    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();
        int current_val = current.first;
        int ops = current.second;

        if (current_val == target_gcd) {
            k_create = ops;
            break;
        }

        for (int x : unique_a) {
            int new_gcd = gcd(current_val, x);
            if (min_ops.find(new_gcd) == min_ops.end()) {
                min_ops[new_gcd] = ops + 1;
                q.push({new_gcd, ops + 1});
            }
        }
    }

    std::cout << k_create + (n - 1) << std::endl;
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
