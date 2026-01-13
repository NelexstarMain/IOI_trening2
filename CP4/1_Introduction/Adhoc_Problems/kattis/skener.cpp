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
    int r, c, rs, cs; std::cin >> r >> c >> rs >> cs;
    std::vector<std::string> res;
    for (int i = 0; i < r; i++) {
        std::string s; std::cin >> s;
        std::string news = "";
        for (char x: s) {
            for (int j = 0; j < cs; j++) {
                news += x;
            }
        }
        for (int j = 0; j < rs; j++) {
            res.PB(news);
        }
    }
    for (auto x: res) std::cout << x << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
