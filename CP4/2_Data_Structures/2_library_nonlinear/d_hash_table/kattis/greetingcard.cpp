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

struct pair_hash {
    size_t operator()(const pii &p) const noexcept {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

void solve() {
    int n; std::cin >> n;
    std::unordered_set<pii, pair_hash> A;
    std::vector<pii> B;
    for (int i = 0; i < n; i++) {
        int x, y; std::cin >> x >> y;
        A.insert({x, y});
        B.PB({x, y});
    }

    int changeX[] = {2018, 0, -2018, 0, 1680, 1680, -1680, -1680, 1118, 1118, -1118, -1118};
    int changeY[] = {0, 2018, 0, -2018, 1118, -1118, 1118, -1118, 1680, -1680, 1680, -1680};

    int count = 0;
    
    for (auto x: B) {
        for (int d = 0; d < 12; d++) {
            int newx = x.F + changeX[d];
            int newy = x.S + changeY[d];
            if (A.find({newx, newy}) != A.end())  count++;
        }
    }
    std::cout << count/2 << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
