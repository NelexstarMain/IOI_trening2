#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

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

#define LSOne(S) ((S) & (-S))

class FenwickTree {
    private:
        vll ft;
    public:
        FenwickTree(int m) {
            vll f(m+1,1);
            build(f);
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
            while (p*2 < SIZE(ft)) p*=2;
            int i = 0;
            while (p) {
                if (i+p < SIZE(ft) && k > ft[i+p]) {
                    i+=p;
                    k-=ft[i];
                }
                p/=2;
            }
            return i+1;
        }
};

void solve() {
    int N; cin >> N;
    vi A(N); for (int& x: A) cin >> x;
    vi B = A; reverse(ALL(B));
    FenwickTree FTA(SIZE(A)), FTB(SIZE(B));
    unordered_map<int, int> AM, BM; // WHERE IT LAY
    for (int i=0; i<SIZE(A); i++) {
        AM[A[i]] = i+1; BM[B[i]] = i+1;
    }
    bool right = false;
    int leftc = 1, rightc = SIZE(B);
    while (leftc <= rightc) {
        if (right) {
            int indx = BM[rightc];
            cout << FTB.rsq(indx-1) << "\n";
            FTB.update(indx, -1);
            FTA.update(AM[rightc], -1);
            rightc--;
        } else {
            int indx = AM[leftc];
            cout << FTA.rsq(indx-1) << "\n";
            FTA.update(indx, -1);
            FTB.update(BM[leftc], -1);
            leftc++;
        }
        right = !right;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
