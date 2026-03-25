#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
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

class SegmentTree {
    private:
        int n;
        vi A, st, lazy;
        int l(int i) { return (i<<1); }
        int r(int i) { return (i<<1)+1; }

        int counquer(int a, int b) {
            if (a == -1) return b;
            if (b == -1) return a;
            return min(a, b);
        }

        void build(int p, int L, int R) {
            if (L == R) {
                st[p] = A[L];
            } else {
                int m = (R+L)/2;
                build(l(p), L, m);
                build(r(p), m+1, R);
                st[p] = counquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != -1) {
                st[p] = lazy[p];
                if (L != R) {
                    lazy[l(p)] = lazy[r(p)] = lazy[p];
                } else {
                    A[L] = lazy[p];
                }
                lazy[p] = -1;
            } 
        }

        int RMQ(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            if (i > j) return -1;
            if ((i<=L) && (j>=R)) return st[p];
            else {
                int m = (L+R)/2;
                return counquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m+1, R, max(m+1, i), j));
            }
        }

        void update(int p, int L, int R, int i, int j, int val) {
            propagate(p, L, R);
            if (i > j) return;
            if ((i<=L) && (R<=j)) {
                lazy[p] = val;
                propagate(p, L, R);
            } else {
                int m = (R+L)/2;
                update(l(p), L, m, i, min(j, m), val);
                update(r(p), m+1, R, max(i, m+1), j, val);
                int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)]: st[l(p)];
                int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)]: st[r(p)];
                st[p] = (lsubtree <= rsubtree) ? st[l(p)]: st[r(p)];
            }
        }

    public:
        SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

        SegmentTree(const vi& initialA) : SegmentTree(SIZE(initialA)) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

        int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }

};

int sbpow(int n) {
    return (int) pow(2, ceil(log2(n)));
} 

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A; for (int i=0; i<n; i++) { int c; cin >> c; A.PB(c); }
    for (int i = n; i < sbpow(n); i++) A.PB(100001);
    // cout << SIZE(A) << "\n";
    SegmentTree ST(A); 
    for (int i=0; i<q; i++) {
        vector<int> R;
        string S; cin >> S;
        string nS = S.substr(6, SIZE(S)-7);
        istringstream iss(nS); string cur;
        while (getline(iss, cur, ',')) R.PB(stoi(cur));
        if (S[0] == 'q') {
            cout << ST.RMQ(R[0]-1, R[1]-1) << "\n";
        } else {
            int firstv = ST.RMQ(R[0]-1, R[0]-1);
            for (int i=0; i<SIZE(R)-1; i++) {
                ST.update(R[i]-1, R[i]-1, ST.RMQ(R[i+1]-1, R[i+1]-1));
            }
            ST.update(R[SIZE(R)-1]-1, R[SIZE(R)-1]-1, firstv);
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
