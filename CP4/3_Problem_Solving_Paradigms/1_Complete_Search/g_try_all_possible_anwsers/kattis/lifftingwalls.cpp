#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<double, double>;
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

int R;
double m=1.0;

vector<pii> DK(vector<pii> A, pii B) {
    // A to som boki tego a B to jest ustawienie wierzy
    // pitagoras dystans
    vector<pii> Res;
    for (auto x: A) {
        if ((x.F-B.F)*m*(x.F-B.F)+(x.S-B.S)*m*(x.S-B.S) <= R*m+1e-6) Res.PB(x);
        // cout << (x.F-B.F)*m*(x.F-B.F)+(x.S-B.S)*m*(x.S-B.S) << "\n";
    }
    return Res;
}

void solve() {
    int l, w, n, r; cin >> l >> w >> n >> r; R=r*r;
    vector<pii> A(n);
    for (int i=0; i<n; i++) cin >> A[i].F >> A[i].S;
    int sum=0, num;
    vector<pii> B={{-(l*m)/2, 0}, {(l*m)/2, 0}, {0, -(w*m)/2}, {0, (w*m)/2}};
    for (int i=0; i<4; i++) {
        int max=0;
        vector<pii> maxv;
        for (int j=0; j<SIZE(A); j++) {
            vector<pii> curr=DK(B, A[j]);
            if (SIZE(curr)>max) {
                maxv=curr;
                max=SIZE(maxv);
            }
        }
        sum+=max;
        if (sum==4) {
            cout << i+1 << "\n";
            return;
        }
        vector<pii> newB;
        for (pii x: B) if (find(ALL(maxv), x)==maxv.end()) newB.PB(x);
        B=newB;
        
    }
    cout << "Impossible\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
