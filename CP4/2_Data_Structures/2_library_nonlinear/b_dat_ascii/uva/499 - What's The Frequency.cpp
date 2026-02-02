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
    std::string line;
    while (std::getline(std::cin, line)) {
        std::map<char, int> allcases;
        int maximum = 0;
        for (char x : line) {
            if (std::isalpha(x)) {
                allcases[x]++;
                maximum = std::max(maximum, allcases[x]);
            }
        }

        if (maximum == 0) return;

        std::vector<char> up, lc;
        for (auto const& [key, value] : allcases) {
            if (value == maximum) {
                if (std::isupper(key)) up.PB(key);
                else lc.PB(key);
            }
        }
        for (char c : up) std::cout << c;
        for (char c : lc) std::cout << c;
        
        std::cout << " " << maximum << std::endl;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
