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

std::map<char, std::vector<std::string>> braille = {
        {'1', {"*.", "..", ".."}},
        {'2', {"*.", "*.", ".."}},
        {'3', {"**", "..", ".."}},
        {'4', {"**", ".*", ".."}},
        {'5', {"*.", ".*", ".."}},
        {'6', {"**", "*.", ".."}},
        {'7', {"**", "**", ".."}},
        {'8', {"*.", "**", ".."}},
        {'9', {".*", "*.", ".."}},
        {'0', {".*", "**", ".."}}
};

void solve() {
    int n;  
    while (std::cin >> n && n != 0) {
        char s; std::cin >> s;
        if (s == 'S') {
            string curr; std::cin >> curr;
            for (int i = 0; i < 3; i++) {
                std::string line = "";
                for (int j = 0; j < SIZE(curr); j++) {
                    line += braille[curr[j]][i];
                    if (j < SIZE(curr)-1) line += " ";
                }
                std::cout << line << "\n";
            }
        } else if (s == 'B') {
            std::vector<std::vector<std::string>> all(n);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < n; j++) {
                    std::string z; std::cin >> z;
                    all[j].PB(z);
                }
            }
            std::string res = "";
            for (auto x: all) {
                for (auto [key, vec]: braille) {
                    if (x==vec) {
                        res += key;
                        continue;
                    }
                }
            }
            std::cout << res << "\n";
            
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
