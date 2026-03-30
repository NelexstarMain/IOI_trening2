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
            return max(a, b);
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
    int N, M;
    bool first = true;
    while (cin >> N && N > 0) {
        if (!first) cout << "\n";
        first = false;
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
            } else if (A.find(S) == A.end()) {
                auto it = A.lower_bound(S);
                int mx = ST.RMQ(it->second, A[E]-1);
                if (mx < ST.RMQ(A[E], A[E])) cout << "maybe\n";
                else cout << "false\n";
            } else if (A.find(E) == A.end()) {
                auto it = A.lower_bound(E);
                auto bit = it;
                bit = prev(it);
                // cout << A[S] << "\n" << ST.RMQ(A[S]+1, bit->second) << "\n" << bit->second << "\n";
                if (bit->second == A[S]) cout << "maybe\n";
                else {
                    int mx = ST.RMQ(A[S]+1, bit->second);
                    if (mx < ST.RMQ(A[S], A[S])) cout << "maybe\n";
                    else cout << "false\n";
                }
            } else {
                int va = ST.RMQ(A[S], A[S]), vb = ST.RMQ(A[E], A[E]); 
                int mx = ST.RMQ(A[S]+1, A[E]-1);
                if (mx < vb && vb <= va) {
                    if (E-S == A[E]-A[S]) cout << "true\n";
                    else cout << "maybe\n";
                } else cout << "false\n";
            }
    }
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}


