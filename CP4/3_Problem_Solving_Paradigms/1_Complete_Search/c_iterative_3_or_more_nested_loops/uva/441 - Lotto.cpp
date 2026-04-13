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
    int N;
    bool first = true;
    while (cin >> N && N > 0) {
        if (!first) cout << "\n";
        first = false;
        vector<int> C(N); for (int &x: C) cin >> x;
        vector<vector<int>> B, A(N); 
        for (int i=0; i<N; i++) A[i].PB(C[i]);
        map<int, int> D; 
        for (int i=0; i<N; i++) { D[C[i]] = i;}
        for (int i=0; i<5; i++) {
            for (auto x: A) {
                // cout << SIZE(x) << "\n";
                int L = x[SIZE(x)-1];
                int ind = D[L];
                // cout << L << "\n" << ind << "\n";
                for (int j=ind+1; j<N; j++) {
                    vector<int> y = x; y.PB(C[j]);
                    // for (int x: y) cout << x << " ";
                    // cout << "\n"; 
                    B.PB(y);
                }
            }
            A = B;
            B.clear();
        }
        // cout << SIZE(A) << "\n";
        for (auto x: A) {
            bool ft = true;
            if (SIZE(x) == 6) for (int n: x) { cout << ((!ft)?" ":"") << n ; ft=false; }
            cout << "\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
