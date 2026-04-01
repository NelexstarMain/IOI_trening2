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
        bool minim;
        int l(int i) { return (i<<1); }
        int r(int i) { return (i<<1)+1; }

        int conquer(int a, int b) {
            if (a == -1) return b;
            if (b == -1) return a;
            if (minim) return min(a, b);
            else return max(a, b);
        }

        void build(int p, int L, int R) {
            if (L == R) {
                st[p] = A[L];
            } else {
                int m = (R+L)/2;
                build(l(p), L, m);
                build(r(p), m+1, R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != -1) {
                st[p] = lazy[p];
                if (L != R) {
                    lazy[l(p)] = lazy[p];
                    lazy[r(p)] = lazy[p];
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
            int m = (L+R)/2;
            return conquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m+1, R, max(m+1, i), j));
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
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

    public:
        SegmentTree(int sz, bool a) : n(sz), A(sz, 0), st(2*sz, 0), lazy(2*sz, -1), minim(a) {}

        SegmentTree(const vi& initialA, bool a) : SegmentTree(SIZE(initialA), a) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

        int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }

};


int sbpow(int n) {
    return (int)(pow(2, ceil(log2(n))));
}

void solve() {
    int N; cin >> N;
    vector<SegmentTree> D1, D2;
    for (int i=0; i<N; i++) {
        vector<int> C(N); for (int &x: C) cin >> x;
        for (int i=N; i<sbpow(N); i++) C.PB(0);
        D2.emplace_back(C, false); D1.emplace_back(C, true);
    }
    int Q; cin >> Q;
    
    while (Q--) {
        int maxim = -INF; 
        int minim = INF;
        char A; cin >> A;
        if (A == 'q') {
            int X, Y, X2, Y2; cin >> X >> Y >> X2 >> Y2; X--; Y--;
            X2--; Y2--;
            for (int i=X; i<=X2; i++) {
                maxim = max(maxim, D2[i].RMQ(Y, Y2));
                minim = min(minim, D1[i].RMQ(Y, Y2));
            }
            cout << maxim << " " << minim << "\n";
        } else {
            int X, Y, val; cin >> X >> Y >> val;
            X--; Y--;
            D2[X].update(Y, Y, val);
            D1[X].update(Y, Y, val);
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}