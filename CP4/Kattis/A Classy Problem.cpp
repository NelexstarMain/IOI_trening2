#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pss = pair<string, string>;

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
// mom: upper-upper-lower-middle class
void solve() {
    int n; std::cin >> n;
    std::vector<pss> a;
    for (int i = 0; i < n; i++) {
        std::string name, s, c, no; std::cin >> name >> s >> c;
        std::string res = "";
        std::stringstream ss(s);
        while (std::getline(ss, no, '-')) {
            if (no == "upper") res += '3';
            else if (no == "middle") res += '2';
            else res += '1';
        }
        std::reverse(ALL(res));
        std::string st = "";
        for (int j = 0; j < (10-SIZE(res)); j++) st += '2';
        res = res + st;
        name = name.substr(0, SIZE(name)-1);
        a.PB({name, res});
    }
    std::sort(ALL(a), [](pss& a, pss& b){
        if (a.S != b.S) return a.S < b.S;
        else return a.F > b.F;
    });
    std::reverse(ALL(a));
    for (int i = 0; i < n; i++) std::cout << a[i].F << "\n";
    std::cout << "==============================\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
