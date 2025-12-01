#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> edges;
    std::vector<std::vector<std::pair<int, int>>> vertices(n + 1);

    // {{num, {steps}}}
    std::vector<std::pair<int, std::vector<int>>> visited;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        edges.push_back({a, b, w});
        vertices[a].push_back({b, w});
    }

    std::queue<int> q;
    q.push(1);
    int last = 1; 
    while (q.size()) {
        int edge = q[0];
        q.pop(0)
        
    }



    
    return 0;
}