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

void solve() {
    std::string l; std::getline(std::cin, l);
    std::stack<char> a;
    bool valid = true;
    for (char x: l) {
        if (x == ' ' || x == '\r' || x == '\n') continue;
        if (x == '(' || x == '[') {
            a.push(x);
        } else {
            if (!a.empty() && ((x == ')' && a.top() == '(') || (x == ']' && a.top() == '['))) {
                a.pop();
            } else {
                valid = false;
                break;
            }
        }
    }
    if (valid && a.empty()) std::cout << "Yes\n";
    else std::cout << "No\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) solve();
    return 0;
}
