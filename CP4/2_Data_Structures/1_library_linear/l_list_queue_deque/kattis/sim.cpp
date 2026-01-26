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
    std::string l; 
    std::getline(std::cin, l);
    std::list<char> A; bool b = true;
    std::list<char>::iterator it = A.end();
    for (char x: l) {
        if (x == ']') {
            it = A.end();
        } else if (x == '[') {
            it = A.begin();
        } else if (x == '<') {
            if (it != A.begin()) {
                it = A.erase(std::prev(it)); 
            }
        } else {
            A.insert(it, x);
        }
    }
    for (std::list<char>::iterator it = A.begin(); it != A.end(); ++it) std::cout << (*it);
    std::cout << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) solve();
    return 0;
}
