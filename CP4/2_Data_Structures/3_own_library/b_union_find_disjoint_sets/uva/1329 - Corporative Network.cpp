#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

struct UnionFind {
    private:
        vector<int> p, rank, setsSizes, weights;
        int numsets;
    public:

        UnionFind(int n) {
            p.assign(n, 0); for (int i=0; i<n; i++) p[i] = i;
            rank.assign(n, 0);            
            weights.assign(n, 0);
            setsSizes.assign(n, 1);
            numsets = n;
        }

        int getweight(int n) { return weights[n]; }
        int findSet(int m) {
            if (m == p[m]) return m;
            int op = p[m]; int root = findSet(op);
            weights[m] += weights[op];
            p[m] = root;
            return root;
}
        bool sameSet(int i, int j) { return ( findSet(i) == findSet(j)); }

        void UnionSet(int i, int j) {
            p[i] = j;
            weights[i] = (abs(i-j)%1000);
        }
};


void solve() {
    int n; cin >> n;
    UnionFind UF(n+1);
    char x;
    while (cin >> x && x != 'O') {
        if (x == 'E') {
            int curr; cin >> curr;
            UF.findSet(curr);
            cout << UF.getweight(curr) << "\n";
        } else if (x == 'I') {
            int a, b; cin >> a >> b;
            UF.UnionSet(a, b);
        }
    }
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
