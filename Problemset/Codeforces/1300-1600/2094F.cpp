#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        if(m%k == 0){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=m; j++){
                    cout << (i+j)%k+1 << ' ';
                }
                cout << '\n';
            }
        }
        else{
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=m; j++){
                    cout << ((i-1)*m+j)%k+1 << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
