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
    std::string l; std::getline(std::cin, l);
    std::vector<int> A(26, 0);
    int maximum = 0;
    for (char x: l) {
        int i = (int)(std::tolower(x)) - 97;
        if (0 <= i && i < 26) {
            A[i]++; maximum = std::max(maximum, A[i]);
        }
    }
    for (int i = 0; i < SIZE(A); i++) {
        if (A[i] == maximum) std::cout << (char)(i+'a');
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) solve();
    return 0;
}
