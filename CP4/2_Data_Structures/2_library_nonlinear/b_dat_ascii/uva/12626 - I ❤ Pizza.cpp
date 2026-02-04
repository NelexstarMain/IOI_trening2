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
    std::string s; std::cin >> s;
    std::vector<int> A(26, 0);
    for (char x: s) {
        int index = int(x);
        if (65 <= index && index <= 90) A[index-65]++;
    }
    int maximum = INF;
    maximum = std::min(maximum, (int)(A[0]/3));
    maximum = std::min(maximum, (int)(A[17]/2));
    maximum = std::min(maximum, (int)(A[12]/1));
    maximum = std::min(maximum, (int)(A[6]/1));
    maximum = std::min(maximum, (int)(A[8]/1));
    maximum = std::min(maximum, (int)(A[19]/1));
    
    std::cout << maximum << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
