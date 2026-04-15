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

int D(int &a, int &b) {
    return (abs((a%5)-(b%5)) + abs((a/5)-(b/5)));
}

void solve() {
    int M=25, A[M]={0};
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int r, c, p; cin >> r >> c >> p;
        A[(r*5+c)]=p;
    }
    int Min=INF;
    vector<int> Winner;
    for (int i=0; i<M; i++) {
        for (int j=i+1; j<M; j++) {
            for (int k=j+1; k<M; k++) {
                for (int a=k+1; a<M; a++) {
                    for (int b=a+1; b<M; b++) {
                        int dis=0;
                        for (int x=0; x<M; x++) if (A[x]>0) dis+=(A[x]*min({D(i,x), D(j,x), D(k,x), D(a,x), D(b,x)}));
                        if (dis<Min) {
                            Winner={i,j,k,a,b}; Min=dis;
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<5; i++) cout << ((i!=0)?" ":"") << Winner[i];
    cout << "\n";
} 

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
