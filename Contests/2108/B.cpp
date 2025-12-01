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

void solve(){
    int n,x;cin>>n>>x;
    int bits=__builtin_popcountll(x);
    if (n<=bits){cout<<x;return;}
    if ((n-bits)%2==0)cout<<x+n-bits;
    else{
        if (x>1){cout<<x+n-bits+1;return;}
        if (x==1){cout<<n+3;return;}
        else{
            if (n==1){cout<<-1;return;}
            else cout<<n+3;
        }
    }
    
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        std::cout << "\n";
    }
    return 0;
}