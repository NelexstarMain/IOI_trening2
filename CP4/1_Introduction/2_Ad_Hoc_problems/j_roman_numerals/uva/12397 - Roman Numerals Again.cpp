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

const vector<pair<string, int>> roman = {
        {"M",  1000},
        {"CM", 900},
        {"D",  500},
        {"CD", 400},
        {"C",  100},
        {"XC", 90},
        {"L",  50},
        {"XL", 40},
        {"X",  10},
        {"IX", 9},
        {"V",  5},
        {"IV", 4},
        {"I",  1}
};

std::map<char, int> costs = {{'I', 1}, {'V', 2}, {'X', 2}, {'L', 2}, {'C', 2}, {'D', 3}, {'M', 4}};

void solve() {
    int n;
    while (std::cin >> n) {
        std::string s = "";
        for (int i = 0; i < roman.size(); i++) {
            int curr = roman[i].second;
            std::string currs = roman[i].first;
            while (n >= curr) {
                n -= curr;
                s += currs;
            }
        }
        int res = 0;
        for (char x: s) {
            res += costs[x];
        }
        std::cout << res << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
