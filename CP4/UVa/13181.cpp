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
    std::string s;
    while (std::cin >> s) {
        int indexs = 0;
        while (s[indexs] != 'X') indexs++;
        int indexe = SIZE(s)-1;
        while (s[indexe] != 'X') indexe--;
        int b = indexs, m = std::max(indexs-1, SIZE(s)-2-indexe);
        // std::cout << indexs << " " << indexe << "\n";
        for (int i = indexs+1; i <= indexe; i++) {
            if (s[i] == 'X') {
                // std::cout << " test " << i-b << " " << (i-b-2)/2 << "\n";
                m = std::max((i-b-2)/2, m);
                b = i;
            }
        }
        std::cout << m << "\n";
    }

}

int main() {
    fast_io();
    solve();
    return 0;
}
