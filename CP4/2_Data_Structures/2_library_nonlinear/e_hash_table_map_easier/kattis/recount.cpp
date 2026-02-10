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
    std::string l;
    std::map<std::string, int> A;
    int m = 0;
    while (std::getline(std::cin, l) && l != "***") {
        A[l]++; m = std::max(m, A[l]);
    }
    int count = 0; std::string first;
    for (auto [k, v]: A) {
        if (v == m) { count++; first = k; }
    }   
    if (count > 1) std::cout << "Runoff!\n";
    else std::cout << first << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
