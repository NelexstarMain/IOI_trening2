#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <map> 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;


    std::vector<std::vector<int>> adj(n + 1); 

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    std::vector<int> permutation(n);

    std::map<int, int> pos_in_permutation; 
    for (int i = 0; i < n; ++i) {
        std::cin >> permutation[i];
        pos_in_permutation[permutation[i]] = i; 
    }

    if (permutation[0] != 1) {
        std::cout << "No\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        std::sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
            return pos_in_permutation[a] < pos_in_permutation[b];
        });
    }

    std::unordered_set<int> visited;
    std::queue<int> q;
    std::vector<int> bfs_generated_order; 

    int start_node = 1; 

    q.push(start_node);
    visited.insert(start_node);
    bfs_generated_order.push_back(start_node);

    int head = 0; 


    while(head < bfs_generated_order.size()) {
        int u = bfs_generated_order[head++]; 

        for (int v : adj[u]) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                bfs_generated_order.push_back(v);
            }
        }
    }
    
    
    if (bfs_generated_order == permutation) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}