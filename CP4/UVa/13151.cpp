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

bool solve() {
    std::string s; std::cin >> s;
    int m; std::cin >> m;
    if (s == "0" && m == 0) return false;
    int points = 0;
    long long i = 0;


    i = std::stoll(s, nullptr, 0);

    for (int j = 0; j < m; j++) {
        std::string d; std::cin >> d;
        long long value; std::cin >> value;
        if (d[0] == '+') {
            i++;
        } else if (d[0] == '-') {
            i--;
        }
        if (i == value) {
            points++;
        } else {
            i = value;
        }
        if (d.size() == 3) {
            if (d[2] == '+') {
                i++;
            } else if (d[2] == '-') {
                i--;
            }
        }
    }
    std::cout << points << "\n";
    return true;
}

int main() {
    fast_io();
    while (solve());
    return 0;
}
