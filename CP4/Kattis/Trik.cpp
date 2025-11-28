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
    std::string s; std::cin >> s;
    int index = 1;
    for (char x: s) {
        if (x == 'A') {
            if (index == 1) {
                index = 2;
            } else if (index == 2) {
                index = 1;
            } 
        } else if (x == 'B') {
            if (index == 2) {
                index = 3;
            } else if (index == 3) {
                index = 2;
            }
        } else {
            if (index == 1) {
                index = 3;
            } else if (index == 3) {
                index = 1;
            }
        }
    }
    std::cout << std::to_string(index) << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
