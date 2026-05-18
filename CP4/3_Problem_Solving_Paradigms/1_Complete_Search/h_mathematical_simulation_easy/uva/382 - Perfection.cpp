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
    int e; vector<int> V;
    while (cin >> e && e!=0) V.PB(e);
    cout << "PERFECTION OUTPUT\n";
    for (int x: V) {
        int C=0;
        for (int i=1; i<=(x/2); i++) {
            if (x%i==0) C+=i;
        }
        string X=to_string(x);
        int S=SIZE(X);
        for (int i=0; i<(5-S); i++) X=" "+X;
        cout << X << "  ";
        if (x==C) cout << "PERFECT\n";
        else if (x<C) cout << "ABUNDANT\n";
        else cout << "DEFICIENT\n";
    } 
    cout << "END OF OUTPUT\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
