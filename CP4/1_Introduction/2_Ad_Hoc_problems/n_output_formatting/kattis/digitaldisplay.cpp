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

std::map<char, std::vector<std::string>> nums = {
    {'0', {
        "+---+  ",
        "|   |  ",
        "|   |  ",
        "+   +  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
    }},
    {'1', {
        "    +  ",
        "    |  ",
        "    |  ",
        "    +  ",
        "    |  ",
        "    |  ",
        "    +  ",
    }},
    {'2', {
        "+---+  ",
        "    |  ",
        "    |  ",
        "+---+  ",
        "|      ",
        "|      ",
        "+---+  ",
    }},
    {'3', {
        "+---+  ",
        "    |  ",
        "    |  ",
        "+---+  ",
        "    |  ",
        "    |  ",
        "+---+  ",
    }},
    {'4', {
        "+   +  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
        "    |  ",
        "    |  ",
        "    +  ",
    }},
    {'5', {
        "+---+  ",
        "|      ",
        "|      ",
        "+---+  ",
        "    |  ",
        "    |  ",
        "+---+  ",
    }},
    {'6', {
        "+---+  ",
        "|      ",
        "|      ",
        "+---+  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
    }},
    {'7', {
        "+---+  ",
        "    |  ",
        "    |  ",
        "    +  ",
        "    |  ",
        "    |  ",
        "    +  ",
    }},
    {'8', {
        "+---+  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
    }},
    {'9', {
        "+---+  ",
        "|   |  ",
        "|   |  ",
        "+---+  ",
        "    |  ",
        "    |  ",
        "+---+  ",
    }},
    {':', {
        "   ",
        "   ",
        "o  ",
        "   ",
        "o  ",
        "   ",
        "   ",
    }}
};

void solve() {
    std::string s; std::cin >> s;
    while (s != "end") {
        for (int i = 0; i < 7; i++) {
            std::string line = "";
            for (char x: s) {
                line += (nums[x][i]);
            }
            line.erase(line.length() - 2);
            std::cout << line << "\n";
        }
        std::cout << "\n\n";
        std::cin >> s;
    }
    std::cout << "end" << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
