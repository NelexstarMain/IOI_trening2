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

int F(int n) { 
    return (2 * (n - (1 << ((int)(log2(static_cast<double>(n)) + 1e-7)))) + 1); 
}

void solve(int z) {
    int N, C=0; cin >> N;
    while (F(N)!=N) {
        C++; N=F(N);
    }
    cout << "Case " << z << ": " << C << " " << N << "\n";
}

int main() {
    fast_io();
    int T, z=1; cin >> T;
    while (T--) solve(z++);
    return 0;
}
