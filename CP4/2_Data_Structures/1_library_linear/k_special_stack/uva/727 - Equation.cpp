#include <bits/stdc++.h>
using namespace std;

int p(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0; 
}

void solve(bool first) {
    std::string l, res = "";
    std::stack<char> a;

    while (std::getline(std::cin, l) && !l.empty()) {
        char c = l[0];
        if (std::isdigit(c)) {
            res += c;
        } else if (c == '(') {
            a.push(c);
        } else if (c == ')') {
            while (!a.empty() && a.top() != '(') {
                res += a.top(); a.pop();
            }
            if (!a.empty()) a.pop();
        } else {
            while (!a.empty() && p(a.top()) >= p(c)) {
                res += a.top(); a.pop();
            }
            a.push(c);
        }
    }
    while (!a.empty()) { res += a.top(); a.pop(); }
    
    if (!first) std::cout << "\n"; 
    std::cout << res << "\n";
}

int main() {
    int T; 
    if (!(cin >> T)) return 0;
    cin.ignore();
    string dummy;
    getline(cin, dummy);
    for (int i = 0; i < T; ++i) solve(i == 0);
    return 0;
}