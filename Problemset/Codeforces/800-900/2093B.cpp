#include <iostream>
#include <string>

void solve() {
    std::string s; std::cin >> s;
    int last = -1;
    for (int i = (int)s.size() - 1; i >= 0; --i)
        if (s[i] != '0') { last = i; break; }
    if (last == -1) { std::cout << "0 0\n"; return; }

    int before = 0, after = 0;
    for (int i = 0; i < last; ++i)
        if (s[i] != '0') before++;
    for (int i = last + 1; i < (int)s.size(); ++i)
        if (s[i] == '0') after++;

    std::cout << before + after << '\n';
}

int main() {
    int t; std::cin >> t;
    while (t--) solve();
}
