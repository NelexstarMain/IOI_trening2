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
const int MOD = 100000007;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    ll N; 
    while (cin >> N && N > 0) {
        ll X=(-7+sqrt((49+24*N))+0.0000001)/12;
        // cout << X << "\n";
        vector<ll> V;
        for (ll i=1; i<=X; i++) {
            if ((ll)(N-6*i*i)%(7*i)==0) {
                ll A=(N-6*i*i)/(7*i);
                V.PB(A);
            }
        }
        sort(ALL(V), [](ll &A, ll &B){
            return A>B;
        });
        if (SIZE(V)>0) for (ll x: V) cout << "Possible Missing Soldiers = " << ((2%MOD)*(x%MOD)*(x%MOD))%MOD << "\n";
        else cout << "No Solution Possible\n";
        cout << "\n";
    } 
}

int main() {
    fast_io();
    solve();
    return 0;
}
