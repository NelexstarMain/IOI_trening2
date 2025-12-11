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

int si = roman.size();

void solve() {
    std::string s;
    while (std::cin >> s) {
        if (std::isdigit(s[0])) {
            int n = std::stoi(s);
            std::string res = "";
            for (int i = 0; i < si; i++) {
                while (n > 0 && n >= roman[i].second) {
                    res += roman[i].first;
                    n -= roman[i].second;
                }
            }
            std::cout << res << "\n";
        } else {
            int index = 0;
            int res = 0;
            for (int i = 0; i < si; i++) {
                while (s.substr(index, roman[i].first.size()) == roman[i].first) {
                    res += roman[i].second;
                    index += roman[i].first.size();
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
