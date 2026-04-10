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

vector<vector<char>> A;
pii con(int i, int j) {
    pii R={0,0};
    int li=i+2, lj=j+2;
    for (int a=i; a<li; a++) {
        for (int b=j; b<lj; b++) {
            // cout << A[a][b] << " ";
            if (A[a][b]=='#') R.F++;
            else if (A[a][b]=='X') R.S++;
        }
    }
    // cout << i << " " << j << " . " << R.F << " " << R.S << "\n";
    return R;
}

void solve() {
    int N, M; cin >> N >> M;
    A.assign(N, vector<char>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char x; cin >> x; 
            A[i][j] = x;
        }
    }
    vector<int> RES(5, 0);
    for (int i=0; i<(N-1); i++) {
        for (int j=0; j<(M-1); j++) {
            pii Curr=con(i, j);
            if (Curr.F!=0) continue;
            RES[Curr.S]++;
        }
    }
    for (int x: RES) cout << x << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
