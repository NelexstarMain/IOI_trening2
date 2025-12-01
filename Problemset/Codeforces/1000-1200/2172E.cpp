#include <bits/stdc++.h>

std::vector<std::string> combs(std::string s) {
    std::sort(s.begin(), s.end());
    std::vector<std::string> res;
    do {
        res.push_back(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return res;
}

void solve() {
    std::string s; std::cin >> s;
    int x, y; std::cin >> x >> y;
    std::vector<std::string> patterns = combs(s);
    std::sort(patterns.begin(), patterns.end());  
    std::string t = patterns[x-1]; std::string u = patterns[y-1];
    std::unordered_map<char, int> ts;
    for (char x: t) ts[x]++;
    std::unordered_map<char, int> us;
    int A = 0;
    for (char x: u) us[x]++;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == u[i]) {
            A++;
        }
    }
    std::cout << A << "A" << (t.size() - A) << "B\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}