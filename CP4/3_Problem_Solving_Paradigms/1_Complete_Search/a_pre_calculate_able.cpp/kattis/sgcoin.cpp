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
    ll V; cin >> V; ll T;
    ll target = 10000000;
    string S1 = "nelek", S2 = "hahah";
    for (ll x: S1) V = (V*31+x)%MOD;
    T = (V*7%MOD);
    cout << S1 << " " << (target-T+MOD)%MOD << "\n"; V = target;
    for (ll x: S2) V = (V*31+x)%MOD;
    T = (V*7%MOD);
    cout << S2 << " " << (target-T+MOD)%MOD << "\n";    
}

int main() {
    fast_io();
    solve();
    return 0;
}
