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
    int N, T=1;
    while (cin >> N && N > 0) {
        vector<int> B, A(N); for (int &x: A) cin >> x;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                B.PB(A[i] + A[j]);
            }
        }
        sort(ALL(B));
        // for (int x: B) cout << x << " ";
        // cout << "\n";
        cout << "Case " << T++ << ":\n";
        int Q; cin >> Q;
        while (Q--) {
            int x; cin >> x;
            auto it = upper_bound(ALL(B), x);
            auto in = it;
            if (it != B.begin()) in = prev(it); int res;
            if (it == B.end()) res = *in;
            else res = (abs(*it-x) < abs(*in-x))?*it:*in;
            cout << "Closest sum to " << x << " is " << res << ".\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
