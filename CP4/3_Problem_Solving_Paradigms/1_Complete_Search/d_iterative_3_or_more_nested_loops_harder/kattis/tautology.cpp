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

string S;
int position;

int eva(int mask) {
    int a=S[position++];
    if (a=='p') return (mask >> 0) & 1;
    if (a=='q') return (mask >> 1) & 1;
    if (a=='r') return (mask >> 2) & 1;
    if (a=='s') return (mask >> 3) & 1;
    if (a=='t') return (mask >> 4) & 1;
    if (a=='N') return !eva(mask);
    int w = eva(mask), x = eva(mask);
    if (a=='K') return (w && x);
    if (a=='A') return (w || x);
    if (a=='C') return (!w || x);
    if (a=='E') return (w==x);
    return 0;
}

void solve() {
    while (cin >> S && S!="0") {
        bool valid=true;
        for (int i=0; i<32&&valid; i++) {
            position=0;
            if (eva(i)==0) valid=false;
        }
        if (valid) cout << "tautology\n";
        else cout << "not\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
