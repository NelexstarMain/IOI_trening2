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
#define LSB(a) (a&(-a))

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class FenwickTree {
    private:
        int n;
        vector<int> ft;
    public:
        FenwickTree(vector<int> &A) : n(SIZE(A)+1) {
            ft.assign(n, 0);
            for (int i=1; i<n; i++) {
                ft[i] += A[i-1];
                if (i+LSB(i)<n) ft[i+LSB(i)] += ft[i];
            } 
        }

        int rsq(int i) {
            int sum = 0;
            for (; i>0; i-=LSB(i)) sum += ft[i];
            return sum;
        }

        int rsq(int i, int j) { return rsq(j) - rsq(i-1); }

        void update(int i, int v) {
            for (; i<n; i+=LSB(i)) {
                ft[i] += v;
            }
        } 
};

void solve() {
    int N;
    bool first = true; int Case = 1;
    while (cin >> N && N > 0) {
        if (!first) cout << "\n"; first = false;
        cout << "Case " << Case++ << ":\n";
        vector<int> B(N); for (int &x: B) cin >> x;
        string A;
        FenwickTree FT(B);
        while (cin >> A && A != "END") {
            if (A == "M") {
                int I, J; cin >> I >> J;
                cout << FT.rsq(I, J) << "\n";
            } else if (A == "S") {
                int X, R; cin >> X >> R;
                FT.update(X, (R-FT.rsq(X, X)));
            }
        }
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
