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
    int si = SIZE(s);
    int c = 1;
    int r = si/c;
    while (!(r <= c && c <= si && si%c==0)) {
        c++;
        r = si/c;
    } 
    std::vector<std::vector<char>> d(r, std::vector<char>(c));
    int index = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            d[j][i] = s[index];
            index++;
        }
    }
    std::string res = "";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res += d[i][j];
        }
    }
    std::cout << res << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
