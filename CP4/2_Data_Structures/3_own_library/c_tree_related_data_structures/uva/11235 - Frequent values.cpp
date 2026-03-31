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
    int N, Q;
    while (cin >> N && N > 0) {
        cin >> Q;
        vector<int> S; int ind = 0;
        map<int, int> B;
        vector<int> A(N); for (int &x : A) cin >> x;
        int val = A[0], beg = 0, cou = 1;
        for (int i=1; i<N; i++) {
            if (A[i] == val) cou++;
            else {
                B[beg] = ind++; S.PB(cou);
                cou = 1; beg = i;
                val = A[i];
            }
        }
        B[beg] = ind; S.PB(cou);
        SegmentTree ST(S);
        while (Q--) {
            int i, j; cin >> i >> j; i--; j--;
            auto St = prev(B.upper_bound(i));
            auto En = prev(B.upper_bound(j));
            int maxim = 0;
            if (St != En) {
                maxim = max(maxim, (St->first+S[St->second]-i));
                maxim = max(maxim, (j-En->first+1));
            } else maxim = max(maxim, (j-i+1));
            
            if (abs(En->second - St->second) > 1) {;
                maxim = max(maxim, ST.RMQ(St->second+1, En->second-1));
            }
            cout << maxim << "\n";
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}