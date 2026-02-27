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

void solve() {
    std::string edge;
    std::unordered_set<char> A;
    int edges = 0;
    while (std::cin >> edge && edge[0] != '*') {
        A.insert(edge[1]); A.insert(edge[3]);
        edges++;
        // std::cout << SIZE(A) << "\n";
    }
    int noedged = 0;
    std::string line; std::cin >> line;
    for (int i = 0; i < SIZE(line); i+=2) {
        if (A.find(line[i]) == A.end()) noedged++;
    }
    std::cout << "There are " << (SIZE(A)-edges) << " tree(s) and " << (noedged) <<  " acorn(s).\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
