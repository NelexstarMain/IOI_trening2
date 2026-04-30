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
    int N, M; 
    while (cin >> N >> M) {
        if (N==0&&M==0) return;
        vector<pii> A(M);
        for (pii &p: A) cin >> p.F >> p.S;
        int S=(1<<N);
        int Ma=0;
        for (int i=0; i<S; i++) {
            // cout << i << "\n";
            bool valid = true;
            for (pii x: A) {
                // cout << x.F << " " << x.S << "\n";
                int Fe=(1<<(x.F-1));
                // cout << Fe << "\n";
                if ((Fe&i)>0) {
                    int Se=(1<<(abs(x.S)-1));
                    // cout << Se << "\n";
                    if (x.S<0 && (Se&i)>0) valid = false;
                    else if (x.S>0 && (Se&i)==0) valid = false;
                    if (!valid) break;
                }
            }
            if (valid) Ma=max(Ma, __builtin_popcount(i));
        }
        cout << Ma << "\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
