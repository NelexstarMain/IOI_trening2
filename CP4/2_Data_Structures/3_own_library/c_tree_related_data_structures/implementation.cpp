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

class FenwicTree {
    private:
        vll ft;
    public:
        FenwicTree(int m) {
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
        FenwicTree(const vll &f) { build(f); }
        
        FenwicTree(int m, const vi &s) {
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
                if (i+p < SIZE(tf) && k > tf[i+p]) {
                    i+=p;
                    k-=tf[i];
                }
                p/=2;
            }
            return i+1;
        }
};
void solve() {
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
