#include <bits/stdc++.h>

// Za wolne podejscie nieprzechodzi testów 
// a jest to spowodowane złym wyborem struktór danych 
// 60%

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

        int RMQ(int p, int L, int R, int i, int j) {
            if (i > j) return -1;
            if ((i<=L) && (j>=R)) return st[p];
            else {
                int m = (L+R)/2;
                return counquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m+1, R, max(m+1, i), j));
            }
        }

        void update(int p, int L, int R, int i, int val) {
            if (L == R) {
                st[p] = val;
                A[L] = val;
                return;
            }
            
            int m = (L + R) / 2;
            if (i <= m) {
                update(l(p), L, m, i, val);
            } else {
                update(r(p), m + 1, R, i, val);
            }
            st[p] = counquer(st[l(p)], st[r(p)]);
        }

    public:
        SegmentTree(int sz) : n(sz), A(n, 0), st(2*n), lazy(2*n, -1) {}

        SegmentTree(const vi& initialA) : SegmentTree(SIZE(initialA)) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int val) { update(1, 0, n-1, i, val); }

        int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }

};

int sbpow(int n) {
    return (int)(pow(2, ceil(log2(n))));
}

class NTree {
    private:
        int S;         
        int T = 0;     
        int P = 0;      
        int M = 0;     
        
        SegmentTree ST; 
        
        unordered_set<int> Check;
        vector<int> TimeToIndex, TimeToValue;
        unordered_map<int, int> ValueToIndex;

    public:
        NTree(int capacity): S(capacity), ST(sbpow(capacity)) {}

        int rmq() {
            return ST.RMQ(0, S - 1);
        }

        void update(int i, int val) {
            ST.update(i, val);
        }

        int getM() { return M; }
        void clearM() { M = 0; }

        void NewE(int value) {
            if (Check.find(value) == Check.end()) {
                int indx; M++;
                if (P >= S) {
                    int smallestTime = rmq();
                    indx = TimeToIndex[smallestTime];
                    Check.erase(TimeToValue[smallestTime]);
                } else {
                    indx = P; 
                    P++;
                }
                
                update(indx, T);
                Check.insert(value); 
                ValueToIndex[value] = indx;
                TimeToIndex.PB(indx);
                TimeToValue.PB(value);
                T++;
            } else {
                int indx = ValueToIndex[value];
                update(indx, T);
                TimeToIndex.PB(indx);
                TimeToValue.PB(value);
                T++; 
            }
        }
};


void solve() {
    int N; cin >> N;
    vector<NTree> A;
    for (int i=0; i<N; i++) { int C; cin >> C; A.PB(NTree(C)); }
    string Com;
    
    while (cin >> Com && Com != "END") {
        if (Com == "RANGE") {
            int b,y,k; cin >> b >> y >> k;
            for (int i=0; i<k; i++) {
                for (auto &x: A) x.NewE((b+y*i));
            }
        } else if (Com == "ADDR") {
            int val; cin >> val;
            for (auto &x: A) x.NewE(val);
        } else {
            for (auto &x: A) {
                cout << x.getM() << " ";
                x.clearM();
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
