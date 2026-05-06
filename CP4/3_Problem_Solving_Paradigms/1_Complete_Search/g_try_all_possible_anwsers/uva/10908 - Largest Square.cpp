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

const int DIR[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<string> A(N); for (string &x: A) cin >> x;
    cout << N << " " << M << " " << Q << "\n"; 
    while (Q--) {
        int r, c; cin >> r >> c;
        int size=1; pii start={r, c}, end={r, c};
        char val=A[r][c];
        bool valid = true;
        while (valid) {
            // increase size
            if (start.F-1>=0 && start.S-1>=0 && end.F+1<N && end.S+1<M) {
                start={start.F-1, start.S-1}; end={end.F+1, end.S+1}; size+=2; 
                pii check={start.F, start.S};
                for (int i=0; i<4; i++) {
                    for (int j=0; j<size-1; j++) {
                        // cout << check.F << " " << check.S << " " << N << " " << M << "\n";
                        if (A[check.F][check.S]!=val) {
                            valid=false;
                        }
                        check={check.F+DIR[i][0], check.S+DIR[i][1]};
                    }
                }
                if (!valid) size-=2;
            } else valid=false;
        }
        cout << size << "\n";
    }
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
