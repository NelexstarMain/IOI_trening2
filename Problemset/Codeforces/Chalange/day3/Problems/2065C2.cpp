#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n, m;

    std::cin >> n >> m;

    std::vector<int> a(n), b(m);

    for (int& x: a) std::cin >> x;
    for (int& x: b) std::cin >> x;

    // plan jest taki że pierwszy elemet muszi być jak najmniejszy a kolejne jak najblizęj jego
    // zrobimy to za pomocom BINARY SEARCH bedziemy najbliszszego elementu po nim 

    int max_b = a + c;
    auto it = std::upper_bound(b.begin(), b.end(), max_b);

    if (it != b.begin()) {
        --it;
        int b_val = *it;
        int new_a = b_val - a;

    } else {

    }

}