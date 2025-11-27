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
    int a, b, c; std::cin >> a >> b >> c;
    std::unordered_map<int, int> lands;
    for (int i = 0; i < b; i++) {
        int x, y; std::cin >> x >> y;
        lands[x] = y;
    }
    std::vector<int> players(a, 1);
    int currpl = 0;
    bool valid = true;
    for (int i = 0; i < c; i++) {
        if (valid) {
            int move; std::cin >> move;
            int newpos = players[currpl] + move;
            if (lands.find(newpos) != lands.end()) {
                newpos = lands[newpos];
            } 
            if (newpos >= 100) {
                newpos = 100;
                valid = false;
            }
            players[currpl] = newpos;
            currpl = (currpl+1)%a;
        } else {
            int move; std::cin >> move;
        }
        
    }
    for (int i = 0; i < a; i++) {
        std::cout << "Position of player " << i+1 << " is " << players[i] << ".\n";
    }
}

int main() {
    fast_io();
    int t; std::cin >> t;
    while (t--) solve();
    return 0;
}
