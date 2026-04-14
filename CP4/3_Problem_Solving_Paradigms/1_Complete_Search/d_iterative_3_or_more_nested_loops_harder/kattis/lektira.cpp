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
    string S; cin >> S;
    vector<string> V;
    int Si = SIZE(S);
    for (int i=1; i<Si-1; i++) {
        for (int j=i+1; j<Si; j++) {
            string A=S.substr(0,i), B=S.substr(i, j-i), C=S.substr(j, Si-j);
            reverse(ALL(A)); reverse(ALL(B)); reverse(ALL(C));
            V.PB(A+B+C);
        }
    }
    sort(ALL(V));
    // cout << SIZE(V) << "\n";
    cout << V[0] << "\n";

}

int main() {
    fast_io();
    solve();
    return 0;
}
