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
    int N, M; cin >> N >> M;
    vector<int> A(M+2); A[0]=0;
    for (int i=0; i<M; i++) cin >> A[i+1];
    A[M+1]=N;
    set<int> D;
    for (int i=0; i<M+2; i++) {
        for (int j=i+1; j<M+2; j++) {
            D.insert(abs(A[j]-A[i]));
        }
    }
    vector<int> B;
    for (int x: D) B.PB(x); 
    for (int i=0; i<SIZE(B); i++) cout << ((i==0)?"":" ") << B[i];
    cout << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
