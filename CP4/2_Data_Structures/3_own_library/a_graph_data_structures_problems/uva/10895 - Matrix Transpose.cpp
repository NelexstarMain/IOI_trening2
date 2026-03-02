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
    int m, n; 
    while (cin >> m >> n) {
        vector<set<pii>> B(n + 1); 
        for (int i = 1; i <= m; i++) {
            vector<int> A;
            int r; cin >> r;
            for (int j = 0; j < r; j++) {
                int z; cin >> z; 
                A.PB(z);
            }
            for (int j = 0; j < r; j++) {
                int val; cin >> val;
                B[A[j]].insert({i, val});
            }
        }

        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++) {
            if (B[i].empty()) {
                cout << "0\n\n";
                continue;
            }
            cout << SIZE(B[i]);
            for (auto const& element : B[i]) {
                cout << " " << element.F;
            }
            cout << "\n";
            bool first = true;
            for (auto const& element : B[i]) {
                if (!first) cout << " ";
                cout << element.S;
                first = false;
            }
            cout << "\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}