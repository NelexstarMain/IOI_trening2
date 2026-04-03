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
    int N; cin >> N;
    vector<int> A(N); vector<bool> B(N, true);
    int C = 0, I = 0;
    while (N-C) {
        C++; 
        for (int i=0; i<C;) {
            I = (I+1)%N;
            if (B[I]) i++;
        }
        A[I] = C; B[I] = false;
        if (C!=N) while (!B[I]) I=(I+1)%N;
    }
    for (int i=0; i<N; i++) cout << ((i==0)?"":" ") << A[i];
    cout << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
