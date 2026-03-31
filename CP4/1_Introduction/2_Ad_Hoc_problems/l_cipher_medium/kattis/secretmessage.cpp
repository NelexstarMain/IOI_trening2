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
    int l = SIZE(s);
    int closest = std::ceil(std::sqrt(l));
    int a = closest*closest;
    std::vector<std::vector<char>> wh(closest, std::vector<char>(closest));
    for (int i = 0; i < (a-l); i++) {
        s += '*';
    }
    for (int i = 0; i < a; i++) {
        int x = i/closest;
        int y = i%closest;
        wh[x][y] = s[i];
    }
    std::string res = "";
    for (int i = 0; i < closest; i++) {
        for (int j = closest-1; j >= 0; j--) {
            if (wh[j][i] != '*') {
                res += wh[j][i];
            }
        }
    }
    std::cout << res << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
