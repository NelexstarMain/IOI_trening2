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
    std::string s;
    int num = 0;
    while (std::cin >> s) {
        num++;
        if (s == "end") break;
        std::vector<char> a;
        for (char x: s) {
            bool find = false;
            for (int i = 0; i<SIZE(a); i++) {
                if (a[i] >= x) {
                    find = true;
                    a[i] = x;
                    break;
                }
            }
            if (!find) a.PB(x);
        }
        std::cout << "Case " << num << ": "  << SIZE(a) << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
