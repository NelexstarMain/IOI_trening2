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
        vi A, st, lazy, flip;
        int l(int i) { return (i<<1); }
        int r(int i) { return (i<<1)+1; }

        int counquer(int a, int b) {
            return a+b;
        }

        void build(int p, int L, int R) {
            if (L == R) {
                st[p] = A[L];
            } else {
                int m = (R+L)/2;
                build(l(p), L, m);
                build(r(p), m+1, R);
                st[p] += counquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != -1) {
                st[p] = lazy[p]*(R-L+1);
                if (L != R) {
                    lazy[l(p)] = lazy[r(p)] = lazy[p];
                } else {
                    A[L] = lazy[p];
                }
                lazy[p] = -1;
            } 
        }

        void flipoperation(int p, int L, int R) {
            if (flip[p] != -1) {
                st[p] = (R-L-st[p]+1);
                if (L != R) {
                    flip[l(p)] = flip[r(p)] = 1;
                } else {
                    A[L] = (R-L-st[p]+1);               
                }
                flip[p] = -1; 
            }
        }

        int RSQ(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            flipoperation(p, L, R);
            if (i > j) return 0;
            if ((i<=L) && (j>=R)) return st[p];
            else {
                int m = (L+R)/2;
                return counquer(RSQ(l(p), L, m, i, min(m, j)), RSQ(r(p), m+1, R, max(m+1, i), j));
            }
        }

        void update(int p, int L, int R, int i, int j, int val) {
            propagate(p, L, R);
            flipoperation(p, L, R);
            if (i > j) return;
            if ((i<=L) && (R<=j)) {
                lazy[p] = val;
                propagate(p, L, R);
            } else {
                int m = (R+L)/2;
                update(l(p), L, m, i, min(j, m), val);
                update(r(p), m+1, R, max(i, m+1), j, val);
                // int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)]*(m-L+1): st[l(p)];
                // int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)]*(R-m): st[r(p)];
                propagate(p, L, R);
                st[p] = counquer(st[l(p)], st[r(p)]);
            }
        }
        void flips(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            flipoperation(p, L, R);
            if (i > j) return;
            if ((i<=L) && (R<=j)) {
                flip[p] = 1;
                flipoperation(p, L, R);
            } else {
                int m = (L+R)/2;
                flips(l(p), L, m, i, min(j, m));
                flips(r(p), m+1, R, max(i, m+1), j);
                flipoperation(p, L, R);
                st[p] = counquer(st[l(p)], st[r(p)]);
            }
        }

    public:
        SegmentTree(int sz) : n(sz), st(4*n, 0), lazy(4*n, -1), flip(4*n, -1) {}

        SegmentTree(const vi& initialA) : SegmentTree(SIZE(initialA)) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

        int RSQ(int i, int j) { return RSQ(1, 0, n-1, i, j); }
        
        void flips(int i, int j) { flips(1, 0, n-1, i, j); }

};

int sbpow(int n) {
    return (int) pow(2, ceil(log2(n)));
} 

void solve() {
    vi A = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    SegmentTree St(A);
    St.flips(0, 1);
    cout << St.RSQ(2,2);

}

int main() {
    solve();
    return 0;
}
