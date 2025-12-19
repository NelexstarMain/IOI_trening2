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
    //65449,8
    double sum = 0.0;
    for (int i = 1; i < 90000; i++) {
        sum += std::pow(std::sin(((double)i/1000)*(std::acos(-1)/100.0)), 2)*25*25*3.141592653589793;
    }
    std::cout << sum*2 << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
