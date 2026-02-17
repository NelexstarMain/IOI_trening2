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
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) (int)((a).size())


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int seed, seed2; std::cin >> seed >> seed2;
    std::string s; s.reserve(10e5+7); s = "0"; int c = 1;
    for (int i = 1; i < 10e4; i++) { if ((seed&(seed2*i)) != 0) c = i%(seed&(seed2*i)); if (c != 0) s += (i%c + '0'); }
    std::cout << s << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    while (T--) solve();
    std::cerr << "time taken : " << (double) clock() / CLOCKS_PER_SEC << " secs" << std::endl;
    
    return 0;
}
