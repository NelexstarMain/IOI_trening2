#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FWD(i, a, b) for(int i = a; i < b; ++i)
#define REV(i, a, b) for(int i = a; i >= b; --i)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int prority(char a) {
    if (a == '*' || a == '/') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    } else {
        return 0;
    }
}

void solve(bool first) {
    std::string l, res = "";
    std::stack<char> a;

    while (std::getline(std::cin, l) && !l.empty())  {
        char c = l[0];
        if (std::isdigit(c)) {
            res += c;
        } else if (c == '(') {
            a.push(c);
        } else if (c == ')') {
            while (!a.empty() && a.top() != '(') {
                res += a.top();
                a.pop();
            }
            a.pop();

        } else {
            while (!a.empty() && prority(c) <= prority(a.top())) {
                res += a.top(); a.pop();
            }
            a.push(c);
        }
    }
    while (!a.empty()) {
        res += a.top(); a.pop();
    }
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
