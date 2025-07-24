#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_map<int, std::vector<int>> costs_to_target;

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int current_ops = 0;
        while (true) {
            costs_to_target[x].push_back(current_ops);
            
            if (x == 0) {
                break;
            }
            x /= 2;
            ++current_ops;
        }
    }

    int min_total_ops = 2e9;

    for (auto const& pair : costs_to_target) {
        const int target_value = pair.first;
        const std::vector<int>& ops_list = pair.second;

        if (ops_list.size() >= k) {
            std::vector<int> current_ops_sorted = ops_list;
            std::sort(current_ops_sorted.begin(), current_ops_sorted.end());

            int current_sum = 0;
            for (int i = 0; i < k; ++i) {
                current_sum += current_ops_sorted[i];
            }
            
            min_total_ops = std::min(min_total_ops, current_sum);
        }
    }

    std::cout << min_total_ops << std::endl;

    return 0;
}