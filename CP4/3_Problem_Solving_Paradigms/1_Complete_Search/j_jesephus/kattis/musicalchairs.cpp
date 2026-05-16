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
    int I=0, N; cin >> N;
    vector<pii> V(N);
    for (int i=0; i<N; i++) {
        int C; cin >> C;
        V[i]={i+1, C};
    }
    for (int j=N; j>1; --j) {
        I=(I)%j;
        int St=V[I].S;
        I=(I+St-1)%(j);
        // cout << V[I].S << "\n";
        V.erase(V.begin()+I);
    }
    // cout << SIZE(V) << "\n";
    cout << V[0].F << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
