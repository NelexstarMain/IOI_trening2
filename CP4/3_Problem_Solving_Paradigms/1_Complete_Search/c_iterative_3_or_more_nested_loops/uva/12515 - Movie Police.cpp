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
    vector<string> A(N); for (string &x: A) cin >> x;
    
    for (int i=0; i<M; i++) {
        int MAX=-INF;
        int INDEX=-1;
        string S; cin >> S;
        for (int z=0; z<N; z++) {
            int localMax=-INF;
            if (SIZE(S)<=SIZE(A[z])) {
                for (int j=0; j<=(SIZE(A[z])-SIZE(S)); j++) {
                    int ind=0;
                    for (int k=0; k<SIZE(S); k++) {
                        if (S[k]==A[z][j+k]) ind++;
                    }
                    localMax=max(localMax, ind);
                }
            }
            if (localMax > MAX) {
                INDEX=(z+1);
                MAX=localMax;
            }
        }
        cout << INDEX << "\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
