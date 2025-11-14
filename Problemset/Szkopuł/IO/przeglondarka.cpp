#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

struct Node {
    Node* children[256] = {nullptr};
    int url_count = 0;  

    int urls_in_subtree = 0;       
    long long edges_in_subtree = 0; 
    int max_depth = -1;             
    char deepest_child_char = 0;  
};

void insert(Node& root, const std::string& url) {
    Node* current = &root;
    for (char ch : url) {
        unsigned char idx = (unsigned char)ch;
        if (!current->children[idx]) {
            current->children[idx] = new Node();
        }
        current = current->children[idx];
    }
    current->url_count = 1;
}

void dfs_calculate(Node* node) {
    if (node->url_count) {
        node->urls_in_subtree = 1;
        node->max_depth = 0;
    }

    for (int i = 0; i < 256; ++i) {
        Node* child_node = node->children[i];
        if (!child_node) continue;

        dfs_calculate(child_node);

        if (child_node->urls_in_subtree > 0) {
            node->urls_in_subtree += child_node->urls_in_subtree;
            node->edges_in_subtree += child_node->edges_in_subtree + 1;

            if (child_node->max_depth + 1 >= node->max_depth) {
                node->max_depth = child_node->max_depth + 1;
                node->deepest_child_char = (char)i;
            }
        }
    }
}


void get_optimal_order(Node* node, std::string& current_path, std::vector<std::string>& order) {
    for (int k = 0; k < node->url_count; ++k)
        order.push_back(current_path);

    std::vector<std::pair<char, Node*>> children_vec;
    for (int i = 0; i < 256; ++i) {
        Node* child = node->children[i];
        if (child && child->urls_in_subtree > 0)
            children_vec.push_back({(char)i, child});
    }

    std::sort(children_vec.begin(), children_vec.end(),
        [](auto& a, auto& b) {
            if (a.second->urls_in_subtree != b.second->urls_in_subtree)
                return a.second->urls_in_subtree > b.second->urls_in_subtree;
            return a.second->max_depth < b.second->max_depth;
        });

    for (auto& [c, child] : children_vec) {
        current_path.push_back(c);
        get_optimal_order(child, current_path, order);
        current_path.pop_back();
    }
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
    long long total_cost = 0;

    std::vector<std::string> visit_order;
    std::string current_path;
    get_optimal_order(root.get(), current_path, visit_order);

    

    std::string res;
    res += visit_order[0];
    res += 'E';
    for (size_t i = 1; i < visit_order.size(); ++i) {
        const std::string& prev = visit_order[i-1];
        const std::string& curr = visit_order[i];
        int lcp_len = 0;
        
        while (lcp_len < prev.length() && lcp_len < curr.length() && prev[lcp_len] == curr[lcp_len]) {
            lcp_len++;
        }
        if (prev.length()-lcp_len + 1 + curr.length()-lcp_len > curr.length()) {
            res += curr;
            res += 'E';
        } else {
            res += 'T'; 
            for (int j = 0; j < prev.length() - lcp_len; ++j) {
                res += 'B'; 
            }
            res += curr.substr(lcp_len);
            res += 'E'; 
        }
        
    }
    std::cout << res.size() << "\n";
    std::cout << res << "\n";

    return 0;
}