
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    long long px, py, qx, qy;
    std::cin >> px >> py >> qx >> qy;

    std::vector<double> lengths(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lengths[i];
    }
    
    double main_dis = std::sqrt(std::pow(static_cast<double>(px - qx), 2) + std::pow(static_cast<double>(py - qy), 2));
    lengths.push_back(main_dis);
    
    std::sort(lengths.begin(), lengths.end());

    double sum_others = 0.0;
    for (size_t i = 0; i < lengths.size() - 1; ++i) {
        sum_others += lengths[i];
    }
    
    if (sum_others >= lengths.back()) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
