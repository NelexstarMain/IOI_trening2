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

vector<int> Sums;

struct UnionFind {
    private:
        vector<int> p, rank, setsSizes;
        int numsets;
    public:

        UnionFind(int n) {
            p.assign(n, 0); for (int i=0; i<n; i++) p[i] = i;
            rank.assign(n, 0);            
            setsSizes.assign(n, 1);
            Sums.assign(n, 1);
            numsets = n;
        }

        int findSet(int m) {
            if (m == p[m]) return p[m];
            return p[m] = findSet(p[m]); // nelek tu był 
        }
        bool sameSet(int i, int j) { return ( findSet(i) == findSet(j)); }

        void UnionSet(int i, int j) {
            int x = findSet(i), y = findSet(j); 
            if (x == y) return;
            if (rank[x] > rank[y]) swap(x, y); // belek tu był
            p[x] = y;
            setsSizes[y] += setsSizes[x];
            Sums[y] += Sums[x];
            rank[y] = std::max(rank[x]+1, rank[y]); // NELEK 
            numsets--;
        }
};


void solve() {
    int n, m; cin >> n >> m;
    UnionFind UF(n);
    for (int i=0; i<n; i++) {;
        int c; cin >> c;
        Sums[i] = c;
    }
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        UF.UnionSet(a, b);
    }
    bool valid = true;
    for (int i=0; i<n; i++) {
        if (Sums[UF.findSet(i)] != 0) valid = false;  
    }
    cout << ((valid)?"POSSIBLE":"IMPOSSIBLE") << "\n";
}

int main() {
    fast_io();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
