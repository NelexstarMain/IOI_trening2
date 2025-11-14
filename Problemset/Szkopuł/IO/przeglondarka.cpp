#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

struct Node {
    std::map<char, Node*> children;
    int url_count = 0;
    int urls_in_subtree = 0;
    long long edges_in_subtree = 0;
    int max_depth = -1;
    char deepest_child_char = 0;

    ~Node() {
        for (auto& [ch, child] : children) {
            delete child;
        }
    }
};

void insert(Node& root, const std::string& url) {
    Node* current = &root;
    for (char ch : url) {
        if (!current->children.contains(ch)) {
            current->children[ch] = new Node();
        }
        current = current->children[ch];
    }
    current->url_count = 1;
}

void dfs_calculate(Node* node) {
    if (node->url_count) {
        node->urls_in_subtree = 1;
        node->max_depth = 0;
    }
    for (auto& [ch, child] : node->children) {
        dfs_calculate(child);
        if (child->urls_in_subtree > 0) {
            node->urls_in_subtree += child->urls_in_subtree;
            node->edges_in_subtree += child->edges_in_subtree + 1;
            if (child->max_depth + 1 >= node->max_depth) {
                node->max_depth = child->max_depth + 1;
                node->deepest_child_char = ch;
            }
        }
    }
}

void get_optimal_order(Node* node, std::string& current_path, std::vector<std::string>& order) {
    for (int k = 0; k < node->url_count; ++k) {
        order.push_back(current_path);
    }
    std::vector<std::pair<char, Node*>> children_vec(node->children.begin(), node->children.end());
    std::sort(children_vec.begin(), children_vec.end(),
        [](const auto& a, const auto& b) {
            if (a.second->urls_in_subtree != b.second->urls_in_subtree) {
                return a.second->urls_in_subtree > b.second->urls_in_subtree;
            }
            return a.second->max_depth < b.second->max_depth;
        });
    for (const auto& [ch, child] : children_vec) {
        current_path.push_back(ch);
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
    std::vector<std::string> visit_order;
    std::string current_path;
    get_optimal_order(root.get(), current_path, visit_order);
    root.reset(); 

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
        if (prev.length() - lcp_len + 1 + curr.length() - lcp_len > curr.length()) {
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