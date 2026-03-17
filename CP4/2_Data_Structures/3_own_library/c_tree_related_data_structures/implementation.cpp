#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull= unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
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

#define LSOne(S) ((S) & (-S))

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

class FenwickTree {
    private:
        vll ft;
    public:
        FenwickTree(int m) {
            ft.assign(m+1, 0);
        }
        void build(const vll &f) {
            int m = SIZE(f)-1;
            ft.assign(m+1, 0);
            for (int i=1; i<=m; i++) {
                ft[i] += f[i];
                if (i+LSOne(i) <= m) {
                    ft[i+LSOne(i)] += ft[i];
                }
            }
        }
        FenwickTree(const vll &f) { build(f); }
        
        FenwickTree(int m, const vi &s) {
            vll f(m+1, 0);
            for (int x: s) {
                f[x]++;
            }
            build(f);
        }
        ll rsq(int j) {
            ll sum = 0;
            for (; j; j-=LSOne(j)) {
                sum += ft[j];
            }
            return sum;
        }
        ll rsq(int i, int j) { return (rsq(j) - rsq(i-1)); }

        void update(int i, ll v) {
            for (; i < SIZE(ft); i += LSOne(i)) {
                ft[i] += v;
            }
        }
        ll select(ll k) {
            int p = 1;
            while (p*2 < SIZE(tf)) p*=2;
            int i = 0;
            while (p) {
                if (i+p < SIZE(tf) && k > ft[i+p]) {
                    i+=p;
                    k-=ft[i];
                }
                p/=2;
            }
            return i+1;
        }
};

class FenwickTree2d {
    private:
        int M, N;
        vector<vll> ft; 

    public:
        FenwickTree2d(int m, int n) : M(m), N(n) {
            ft.assign(m + 1, vll(n + 1, 0));
        }
        void build(const vector<vll> &f) {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    update(i, j, f[i][j]);
                }
            }
        }

        void update(int r, int c, ll v) {
            for (int i = r; i <= M; i += LSOne(i)) {
                for (int j = c; j <= N; j += LSOne(j)) {
                    ft[i][j] += v;
                }
            }
        }

        ll rsq(int r, int c) {
            ll sum = 0;
            for (int i = r; i > 0; i -= LSOne(i)) {
                for (int j = c; j > 0; j -= LSOne(j)) {
                    sum += ft[i][j];
                }
            }
            return sum;
        }
        ll rsq(int r1, int c1, int r2, int c2) {
            return rsq(r2, c2) - rsq(r1 - 1, c2) - rsq(r2, c1 - 1) + rsq(r1 - 1, c1 - 1);
        }
};
RUPQ {
    private:
        FenwickTree ft;
    public:
        RUPQ(int m) : ft(FenwickTree(m)) {}
        void update(int i, int v) {
            ft.update(i, v);
        }
        void update(int i, int j, int v) {
            ft.update(i, v);
            ft.update(j+1, -v);
        }
        ll query(int i) {
            ft.rsq(i);
        }
}
class RURQ  {                                    
    private:                                     
        RUPQ rupq;                              
        FenwickTree purq;                       
    public:
        RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} 
        void range_update(int ui, int uj, ll v) {
            rupq.range_update(ui, uj, v);                
            purq.update(ui, v*(ui-1));                   
            purq.update(uj+1, -v*uj);                    
        }
        ll rsq(int j) {
            return rupq.point_query(j)*j -               
                purq.rsq(j);                          
        }
        ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } 
};
void solve() {
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
