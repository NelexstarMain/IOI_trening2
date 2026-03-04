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
        vector<int> p, rank, setsSizes;
        int numsets;
    public:
        UnionFind(int n) {
            p.assign(n, 0); for (int i=0; i<n; i++) p[i] = i;
            rank.assign(n, 0);            
            setsSizes.assign(n, 1);
            numsets = n;
        }

        int findSet(int m) {
            // idziemy po rodzicu do góry dodajemy tez indexy pokolei do korzeniaj potem 
            // jak znajdziemy rodzica to wszyskie podłanczamy do korzenia
            if (m == p[m]) return p[m];
            return p[m] = findSet(p[m]);
        }
        bool sameSet(int i, int j) { return ( findSet(i) == findSet(j)); }

        void UnionSet(int i, int j) {
            int x = findSet(i), y = findSet(j);
            if (x == y) return;
            if (rank[x] > rank[y]) swap(x, y);
            p[x] = y;
            setsSizes[y] += setsSizes[x];
            rank[y] = std::max(rank[x]+1, rank[y]);
            numsets--;
        }
};


void solve() {
    int n, m; cin >> n >> m;
    UnionFind UF(n);
    for (int i=0; i<m; i++) {
        char action; cin >> action;
        int x, y; std::cin >> x >> y;
        if (action == '?') cout << ((UF.sameSet(x, y) == 0) ? "no": "yes") << "\n";
        else UF.UnionSet(x, y);
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
