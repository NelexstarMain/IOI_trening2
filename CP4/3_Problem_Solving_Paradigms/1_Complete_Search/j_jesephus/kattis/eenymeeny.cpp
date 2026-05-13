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
    string l; getline(cin, l); string S;
    stringstream ss(l); int k=0, I=-1;
    while (ss >> S) k++;
    // cout << k << "\n";
    int N; cin >> N;
    vector<string> Fi, Se, A(N); for (string &x: A) cin >> x;
    bool first=true;
    for (int i=0; i<N; i++) {
        for (int j=0; j<k;) {
            I=(I+1)%N;
            if (A[I]!="<0>") j++;
            // if (i==0) cout << I << "\n";
        }
        if (first) Fi.PB(A[I]);
        else Se.PB(A[I]);
        first=!first;
        A[I]="<0>";
    }
    cout << SIZE(Fi) << "\n";
    for (string x: Fi) cout << x << "\n";
    cout << SIZE(Se) << "\n";
    for (string x: Se) cout << x << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
