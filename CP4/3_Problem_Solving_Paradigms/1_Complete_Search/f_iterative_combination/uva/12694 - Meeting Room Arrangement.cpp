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
    int x, y;
    vector<pii> A; 
    int M=0;
    while (cin >> x >> y) {
        if (x==0&&y==0) break;
        M++;
        A.PB({x, y});
    }
    sort(ALL(A));
    int N=(1<<M);
    int Ma=0;
    for (int i=0; i<N; i++) {
        int last=-1;
        bool valid=true;
        for (int j=0; j<M; j++) {
            int mask=(1<<j);
            if ((mask&i)>0) {
                if (A[j].F < last) valid=false;
                if (!valid) break;
                last=A[j].S;
            } 
        }
        if (valid) Ma=max(Ma, __builtin_popcount(i));
    }
    cout << Ma << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
