#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using prio_map = std::map<char, int>;

using ll = long long;
using pii = std::pair<int, int>; 
const pii NOT_FOUND = {-1, -1}; 
prio_map prio;
const std::string order = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int X_MAX, Y_MAX;

void draw_line(std::vector<std::string>& map, pii start, pii end) {
    int x1 = start.first;
    int y1 = start.second;
    int x2 = end.first;
    int y2 = end.second;

    if (y1 == y2) {
        int x_min = std::min(x1, x2);
        int x_max = std::max(x1, x2);
        for (int x = x_min + 1; x < x_max; ++x) {
            char& current = map[y1][x];
            if (current == '|') {
                current = '+';
            } else if (current == '.') {
                current = '-';
            }
        }
    } else if (x1 == x2) {
        int y_min = std::min(y1, y2);
        int y_max = std::max(y1, y2);
        for (int y = y_min + 1; y < y_max; ++y) {
            char& current = map[y][x1];
            if (current == '-') {
                current = '+';
            } else if (current == '.') {
                current = '|';
            }
        }
    }
}

void solve() {
    std::string line;
    std::vector<std::string> input_lines;
    
    if (!std::getline(std::cin, line) || line.empty()) {
        return; 
    }
    
    bool first_image = true; 
    do {
        input_lines.push_back(line);
    } while (std::getline(std::cin, line) && !line.empty());
    
    if (input_lines.empty()) return;

    Y_MAX = input_lines.size();
    X_MAX = input_lines[0].size(); 

    std::vector<pii> points(order.size(), NOT_FOUND);
    int max_dot_index = -1;

    for (int y = 0; y < Y_MAX; ++y) {
        for (int x = 0; x < X_MAX; ++x) {
            char point_char = input_lines[y][x];
            if (point_char != '.') {
                int index = prio[point_char];
                points[index] = {x, y};
                max_dot_index = std::max(max_dot_index, index);
            }
        }
    }

    std::vector<std::string> map = input_lines;
    for (int i = 0; i < max_dot_index; ++i) {
        pii current = points[i];
        pii next = points[i + 1];

        if (current != NOT_FOUND && next != NOT_FOUND) {
            draw_line(map, current, next);
        }
    }
    for (const auto& row : map) {
        std::cout << row << "\n";
    }
}

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    fast_io();
    

    for (int i = 0; i < order.size(); i++) {
        prio.insert({order[i], i});
    }
    int image_count = 0;
    while (std::cin.peek() != EOF) {
        if (image_count > 0) {
            std::cout << "\n";
        }
        
        solve();
        image_count++;
        std::string dummy;
        while (std::cin.peek() == '\n' || std::cin.peek() == '\r') {
            std::getline(std::cin, dummy);
        }
    }
    
    return 0;
}