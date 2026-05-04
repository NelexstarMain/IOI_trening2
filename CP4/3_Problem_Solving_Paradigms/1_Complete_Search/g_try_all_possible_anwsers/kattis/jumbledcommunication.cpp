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
    map<int, int> B;
    for (int i=0; i<256; i++) {
        int val=(i^(i<<1))&255;
        B.insert({val, i});
    }
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int c; cin >> c;
        cout << ((i!=0)?" ":"") << B[c];
    }
    // cout << "\n" << (187^(187<<1)) << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
