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

        int conquer(int a, int b) {
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
        SegmentTree(int sz) : n(sz), A(sz, 0), st(4*sz, 0), lazy(4*sz, -1) {}

        SegmentTree(const vi& initialA) : SegmentTree(SIZE(initialA)) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

        int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }

};

void solve() {
    int N, M; cin >> N;
    if (N == 0) {
        cin >> M; 
        if (M == 0) return;
    }
    map<int, int> A;
    vi B;
    for (int i=0; i<N; i++) {
        int X, Y; cin >> X >> Y;
        A[X] = i; B.PB(Y);
    }
    SegmentTree ST(B);
    cin >> M; 
    for (int i=0; i<M; i++) {
        int S, E; 
        cin >> S >> E;
        int V = INF;
        if (A.find(S) == A.end() && A.find(E) == A.end()) {
            cout << "maybe\n"; continue;
        }

        if (A.find(S) != A.end()) V = min(V, ST.RMQ(A[S]));
        if (A.find(E) != A.end()) V = min(V, ST.RMQ(A[E]));

        auto it_start = A.lower_bound(S);
        auto it_end = A.upper_bound(E);
        int idx_S = it_start->second; 
        auto it_last_valid = prev(it_end);
        int idx_E = it_last_valid->second;
        int max_opad = ST.RMQ(idx_S, idx_E);
        if (max_opad > V) cout << "false";
}

int main() {
    fast_io();
    solve();
    return 0;
}


