#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

struct Node {
    std::map<char, std::unique_ptr<Node>> children;
    int url_count = 0;  

    int urls_in_subtree = 0;       
    long long edges_in_subtree = 0; 
    int max_depth = -1;             
    char deepest_child_char = 0;  
};

void insert(Node& root, const std::string& url) {
    Node* current = &root;
    for (char ch : url) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = std::make_unique<Node>();
        }
        current = current->children[ch].get();
    }
    current->url_count = true;
}

void dfs_calculate(Node* node) {
    if (node->url_count) {
        node->urls_in_subtree = 1;
        node->max_depth = 0;
    }

    for (auto const& [key, val] : node->children) {
        Node* child_node = val.get();
        dfs_calculate(child_node);

        if (child_node->urls_in_subtree > 0) {
            node->urls_in_subtree += child_node->urls_in_subtree;
            node->edges_in_subtree += child_node->edges_in_subtree + 1; 
            
            if (child_node->max_depth + 1 >= node->max_depth) {
                node->max_depth = child_node->max_depth + 1;
                node->deepest_child_char = key;
            }
        }
    }
}

void get_optimal_order(Node* node, std::string current_path, std::vector<std::string>& order) {
    for (int k = 0; k < node->url_count; ++k)
        order.push_back(current_path);

    std::vector<std::pair<char, Node*>> children;
    for (auto& [c, ptr] : node->children)
        if (ptr->urls_in_subtree > 0)
            children.push_back({c, ptr.get()});

    std::sort(children.begin(), children.end(),
              [](auto& a, auto& b) {
                  return a.second->urls_in_subtree > b.second->urls_in_subtree;
              });

    for (auto& [c, child] : children)
        get_optimal_order(child, current_path + c, order);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    auto root = std::make_unique<Node>();
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        insert(*root, s);
    }


    dfs_calculate(root.get());
    long long total_edges = root->edges_in_subtree;
    int max_depth = root->max_depth;
    long long traversal_cost = 2 * total_edges - max_depth;
    long long total_cost = traversal_cost + n + (n > 1 ? n - 1 : 0);

    std::cout << total_cost << "\n";


    std::vector<std::string> visit_order;
    get_optimal_order(root.get(), "", visit_order);
    
    std::cout << visit_order[0] << 'E';

    for (size_t i = 1; i < visit_order.size(); ++i) {
        const std::string& prev = visit_order[i-1];
        const std::string& curr = visit_order[i];
        int lcp_len = 0;
        while (lcp_len < prev.length() && lcp_len < curr.length() && prev[lcp_len] == curr[lcp_len]) {
            lcp_len++;
        }

        std::cout << 'T'; 
        for (int j = 0; j < prev.length() - lcp_len; ++j) {
            std::cout << 'B'; 
        }
        std::cout << curr.substr(lcp_len);
        std::cout << 'E'; 
    }
    std::cout << "\n";

    return 0;
}