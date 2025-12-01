#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::queue<std::pair<int, int>> q;
    std::unordered_set<int> visited;

    q.push({n, 0});
    visited.insert(n);

    while (!q.empty()) {
        int current_num = q.front().first;
        int clicks = q.front().second;
        q.pop();

        if (current_num == m) {
            std::cout << clicks << std::endl;
            return 0;
        }

        int next_mult = current_num * 2;
        if (next_mult < 20000 && visited.find(next_mult) == visited.end()) {
            visited.insert(next_mult);
            q.push({next_mult, clicks + 1});
        }
        
        int next_sub = current_num - 1;
        if (next_sub > 0 && visited.find(next_sub) == visited.end()) {
            visited.insert(next_sub);
            q.push({next_sub, clicks + 1});
        }
    }

    return 0;
}