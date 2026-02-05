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
    
    std::string s; std::cin >> s;
    bool M = false, E = false;
    int x = 0, y = 0, z = 0;
    for (char c: s) {
        if (c == '?') {
            if (!M && !E) x++;
            else if (M && !E) y++;
            else z++;
        } else if (c == 'M') {
            if (!M && !E) M = true;
            else {
                std::cout << "no-theorem\n";
                return;
            }
        } else if (c == 'E') {
            if (M && !E) E = true;
            else {
                std::cout << "no-theorem\n";
                return;
            }
        } else {
            std::cout << "no-theorem\n";
            return;
        }
    }
    if (M && x > 0 && y > 0 && z > 0 && (x+y==z)) std::cout << "theorem\n";
    else std::cout << "no-theorem\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
