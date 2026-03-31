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
    int count = 0;
    while (std::cin >> l) {
        int f = 0, s = 0, r = 0;
        int i = 0;
        while (i < SIZE(l) && std::isdigit(l[i])) {
            f = f*10+(l[i]-'0');
            i++;
        }
        bool add = (l[i] == '+');
        i++;
        while (i < SIZE(l) && std::isdigit(l[i])) {
            s = s*10+(l[i]-'0');
            i++;
        }
        i++;
        while (i < SIZE(l) && std::isdigit(l[i])) {
            r = r*10+(l[i]-'0');
            i++;
        }
        if (add) count += (r == (f+s));
        else count += (r == (f-s));
    }
    std::cout << count << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
