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
    int n; std::cin >> n;
    std::map<char, int> A;
    for (int i = 0; i < n; i++) {
        char c; int num; std::cin >> c >> num;
        A.insert({c, num});
    }
    int k, price = 0; std::cin >> k;
    std::cin.ignore();
    std::string line;
    for (int i = 0; i < k; i++) {
        std::getline(std::cin, line);
        for (char x: line) {
            if (A[x] > 0) price += A[x];
        }
    }
    int dollars = price / 100;
    int cents = price % 100;
    std::cout << dollars << "." << (cents < 10 ? "0" : "") << cents << "$\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
