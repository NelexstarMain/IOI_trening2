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

// 3
// SET 0
// CLEAR 1
// AND 2 2
// 6
// SET 31
// SET 30
// CLEAR 29
// AND 29 30
// OR 29 30
// AND 30 28
// 0

void solve() {
    int n; 
    while (std::cin >> n && n > 0) {
        std::vector<int> a(32, -1);
        for (int i = 0; i < n; i++) {
            std::string s; std::cin >> s;
            int x = 0, y = 0; 
            if (s == "SET") {
                cin >> x; 
                a[x] = 1; // Przypisanie
            } else if (s == "CLEAR") {
                cin >> x; 
                a[x] = 0; // Przypisanie
            } else if (s == "AND") {
                cin >> x >> y; 
                if (a[x] == 0 || a[y] == 0) a[x] = 0;
                else if (a[x] == 1 && a[y] == 1) a[x] = 1;
                else a[x] = -1;
            } else if (s == "OR") {
                cin >> x >> y; 
                if (a[x] == 1 || a[y] == 1) a[x] = 1;
                else if (a[x] == 0 && a[y] == 0) a[x] = 0;
                else a[x] = -1;
            }
        }
        std::reverse(ALL(a));
        for (int x: a) std::cout << (x == -1 ? '?' : (char)(x + '0'));
        std::cout << "\n";
    }

}

int main() {
    fast_io();
    solve();
    return 0;
}
