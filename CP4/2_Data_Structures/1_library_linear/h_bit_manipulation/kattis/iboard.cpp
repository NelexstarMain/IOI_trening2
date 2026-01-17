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

// Keep up the good work.
// iBoard Rules!!
// qwerty


void solve() {
    std::string l; 
    // std::cout << n << " " << (32 - __builtin_clz(n) - __builtin_popcount(n)) << "\n";
    while (std::getline(std::cin, l)) {
        int ones = 0, zeros = 0, code = 0;
        for (char x: l) {
            code = (int)(x);
            ones = ones + __builtin_popcount(code);
            zeros = zeros + (7 - __builtin_popcount(code));
        }
        if (ones%2==1 || zeros%2==1) std::cout << "trapped\n";
        else std::cout << "free\n";
    }
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
