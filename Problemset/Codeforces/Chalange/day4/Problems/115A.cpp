#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> manager_map;
std::vector<int> memo_depth;

int calculate_depth(int employee_id) {
    if (memo_depth[employee_id] != 0) {
        return memo_depth[employee_id];
    }

    if (manager_map[employee_id] == -1) {
        memo_depth[employee_id] = 1;
        return 1;
    }

    int depth = 1 + calculate_depth(manager_map[employee_id]);
    memo_depth[employee_id] = depth;
    return depth;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    manager_map.resize(n + 1);
    memo_depth.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> manager_map[i];
    }

    int max_overall_depth = 0;

    for (int i = 1; i <= n; ++i) {
        max_overall_depth = std::max(max_overall_depth, calculate_depth(i));
    }

    std::cout << max_overall_depth << std::endl;

    return 0;
}