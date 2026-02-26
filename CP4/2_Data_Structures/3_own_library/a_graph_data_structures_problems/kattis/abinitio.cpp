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

// 3 2 8
// 0 1
// 0 2
// 2 1 2
// 1
// 2 3 0
// 4 0 2
// 3 0
// 2 0 3
// 6
// 5

std::pair<char, char> tf = {'0', '1'}; 

void addV(std::vector<std::vector<char>>& a) {
    std::vector<char> b;
    for (int i = 0; i < SIZE(a); i++) {
        a[i].PB(tf.S); b.PB(tf.S);
    }
    b.PB(tf.S); a.PB(b);
}

void clear(std::vector<std::vector<char>>& a, int v) {
    for (int i = 0; i < SIZE(a); i++) {
        a[i][v] = tf.S; a[v][i] = tf.S;
    }
}

void solve() {
    int v, e, q; std::cin >> v >> e >> q;
    std::vector<std::vector<char>> AM(v, std::vector<char>(v, tf.S));
    bool transposed = false;
    for (int i = 0; i < e; i++) {
        int x, y; std::cin >> x >> y;
        AM[x][y] = tf.F;
    } 
    for (int i = 0; i < q; i++) {
        int action; std::cin >> action;
        if (action == 1) addV(AM);
        else if (action == 2) {
            int x, y; std::cin >> x >> y;
            if (transposed) AM[y][x] = tf.F;
            else AM[x][y] = tf.F;
        } else if (action == 3) {
            int x; std::cin >> x;
            clear(AM, x);
        } else if (action == 4) {
            int x, y; std::cin >> x >> y;
            if (transposed) AM[y][x] = tf.S;
            else AM[x][y] = tf.S;
        } else if (action == 6) {
            int x = tf.F, y = tf.S;
            tf.F = y, tf.S = x;
        } else if (action == 5) transposed = !transposed;
    }
    std::cout << SIZE(AM) << "\n";
    for (int i = 0; i < SIZE(AM); i++) {
        ll curr = 1, sum = 0, count = 0;
        for (int j = 0; j < SIZE(AM); j++) {
            if (i == j) continue;
            bool exists = (transposed ? AM[j][i] : AM[i][j]) == tf.F;
            if (exists) {
                sum = (sum + (ll)j * curr) % INF;
                curr = (curr*7)%INF;
                count++;
            }
        }
        std::cout << count << " " << sum << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
