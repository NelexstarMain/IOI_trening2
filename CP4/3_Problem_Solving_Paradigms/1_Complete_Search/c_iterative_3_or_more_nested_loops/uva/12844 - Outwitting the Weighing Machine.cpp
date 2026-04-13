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


void solve(int z) {
    cout << "Case " << z << ":";
    vector<int> A(10); for (int &x: A) cin >> x;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                if (i==j || i==k || j==k) continue;
                int a=(A[i]-A[j]+A[k])/2;
                for (int z=0; z<10; z++) {
                    
                    if (z==i || z==j || z==k) continue;
                    vector<int> R={a, A[i]-a, A[j]-a, A[k]-a, A[z]-a};
                    vector<int> Check;
                    for (int x=0; x<5; x++) {
                        for (int y=x+1; y<5; y++) {

                            Check.PB(R[x]+R[y]);
                        }
                    }
                    sort(ALL(Check));
                    if (Check==A) {
                        sort(ALL(R));
                        for (int x: R) cout << " " << x;
                        cout << "\n";
                        return;
                    } 
                }
            }
        }
    }
        
}

int main() {
    fast_io();
    int T; cin >> T;
    int z=1;
    while (T--) solve(z++);
    return 0;
}
