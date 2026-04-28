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

int F=0, E=0;
vector<pii> B;

bool check(vector<pii> &A) {
    if ( (A[0].F+A[1].F+A[2].F == E) && (A[0].S == E && A[1].S == E && A[2].S == E) ) return true;
    if ( (A[0].F+A[1].F == E) && (A[0].S == A[1].S) && (A[0].S+A[2].S == E) && (A[2].F == E) ) return true;
    return false;
}

void solve() {
    for (int i=0; i<3; i++) {
        int a, b; cin >> a >> b;
        B.PB({a, b});
        F+=(a*b);
    }
    E=sqrt(F);
    sort(ALL(B));
    bool valid=false;
    do {
        for (int i=0; i<8; i++) {
            vector<pii> A=B;
            if (i&1) swap(A[0].F, A[0].S);
            if (i&2) swap(A[1].F, A[1].S);
            if (i&4) swap(A[2].F, A[2].S);
            if (check(A)) valid=true;
        }
    } while (next_permutation(ALL(B)));
    if (valid) cout << "YES\n";
    else cout << "NO\n"; 
}

int main() {
    fast_io();
    solve();
    return 0;
}
