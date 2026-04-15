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

void solve(int z) {
    map<int, vector<pair<int, string>>, greater<int>> A;
    for (int i=0; i<10; i++) {
        string S; int att, def; cin >> S >> att >> def;
        A[att].PB({def, S});
    }
    int counter=1;
    vector<string> At, De;
    for (auto [key, val]: A) {
        sort(ALL(val), [](pair<int, string> &x, pair<int, string> &y) {
            if (x.F!=y.F) return x.F < y.F;
            return x.S < y.S;
        });
        for (auto x: val) {
            if (counter<=5) At.PB(x.S);
            else De.PB(x.S);
            counter++;
        }
    }
    sort(ALL(At)); sort(ALL(De));
    cout << "Case " << z << ":\n(";
    for (int i=0; i<5; i++) cout << ((i>0)?", ":"") << At[i];
    cout << ")\n(";
    for (int i=0; i<5; i++) cout << ((i>0)?", ":"") << De[i];
    cout << ")\n";

}

int main() {
    fast_io();
    int T; cin >> T;
    int z=1;
    while (T--) solve(z++);
    return 0;
}
