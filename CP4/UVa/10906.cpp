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

// 2
// 2
// A=2+3
// B=A+A
// 3
// A=2+3
// B=A+4
// C=B+5

void solve() {
    int n; std::cin >> n;
    std::map ver;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string name, trash, curr; ss >> name;
        ss >> trash;
        std::vector<std::string> all;
        while (ss >> curr) all.PB(curr);
        std::string res = "";
        std::string before = all[0];
        for (int i = 1; i < SIZE(all); i++) {

        }

    }
}

int main() {
    fast_io();
    int t = 1;
    if(!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
