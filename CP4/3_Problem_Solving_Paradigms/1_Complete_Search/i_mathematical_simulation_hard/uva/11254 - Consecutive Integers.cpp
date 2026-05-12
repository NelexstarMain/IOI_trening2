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
    int N; 
    while (cin >> N && N>=0) {
        int D=sqrt(2*N)+1;
        for (int r=D; r>0; --r) {
            if ((2*N)%(r)==0) {
                int s=2*N/r;
                if ((s+r-1)%2==0 && (s-r+1)%2==0 && (s-r+1)>0) {
                    //8=8+...+8
                    cout << N << " = " << (s-r+1)/2 << " + ... + " << (s+r-1)/2 << "\n";
                    break;
                }
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
