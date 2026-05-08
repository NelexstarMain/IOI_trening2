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
    int n, p, k; cin >> n >> p >> k;
    vector<double> A; A.PB(0);
    for (int i=0; i<n; i++) {int c; cin >> c; A.PB(c);}
    A.PB(k*1.0);
    double c=1.0, s=0.0;
    for (int i=1; i<=n+1; i++) {
        s+=(A[i]-A[i-1])*c;
        c+=(p/100.0);
    }
    cout << fixed << setprecision(3) << s << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
