#include <bits/stdc++.h>

using namespace std;


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool solve() {
    int n, m; std::cin >> n >> m;
    if (n == 0 && m == 0) {
        return false;
    }
    std::vector<int> nv(n), mv(m);
    for (int& x: nv) std::cin >> x;
    for (int& x: mv) std::cin >> x;
    std::unordered_set<int> nus, mus, common;
    for (int x: nv) {
        nus.insert(x);
    }
    for (int x: mv) {
        mus.insert(x);
        if (nus.find(x) != nus.end()) {
            common.insert(x);
        }
    }
    for (int x: common) {
        mus.erase(x);
        nus.erase(x);
    }

    std:cout << std::min(mus.size(), nus.size()) << "\n";
    return true;

}

int main() {
    fast_io();
    while (solve());
}
