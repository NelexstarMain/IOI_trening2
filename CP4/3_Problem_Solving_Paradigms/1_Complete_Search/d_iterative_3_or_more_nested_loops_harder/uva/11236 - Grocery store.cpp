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
    ll M=2000;
    for (ll i=1; i<=500; i++) {
        for (ll j=i; i+3*j<=M; j++) {
            for (ll k=j; i+j+2*k<=M; k++) {
                ll c=(i+j+k)*1000000LL, n=(i*j*k)-1000000LL; ll d;
                if (n>0 && c%n==0) d = (c/n);
                else continue;
                if (((i+j+k+d)<=M)&&(d>=k)) {
                    cout << fixed << setprecision(2) << i/100.0 << " " << j/100.0 << " " << k/100.0 << " " << d/100.0;
                    cout << "\n";
                }
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
