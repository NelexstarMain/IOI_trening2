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
    int N=12;
    vector<string> S(N); for (string &x: S) cin >> x;
    bool any = false;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                if (i==j || i==k || j==k) continue;
                string A=S[i], B=S[j], C=S[k];
                bool valid = true;
                for (int z=0; z<4; z++) {
                    if ((A[z]==B[z] && A[z]==C[z] && B[z]==C[z]) || (A[z]!=B[z] && A[z]!=C[z] && B[z]!=C[z])) continue;
                    else valid = false;
                }
                if (valid) { cout << i+1 << " " << j+1 << " " << k+1 << "\n"; any = true; }
            }
        }
    }
    if (!any) cout << "no sets\n"; 
}

int main() {
    fast_io();
    solve();
    return 0;
}
