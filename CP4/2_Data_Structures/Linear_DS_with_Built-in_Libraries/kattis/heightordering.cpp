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

// 4
// 1 900 901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919
// 2 919 918 917 916 915 914 913 912 911 910 909 908 907 906 905 904 903 902 901 900
// 3 901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919 900
// 4 918 917 916 915 914 913 912 911 910 909 908 907 906 905 904 903 902 901 900 919

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(20); for (int& x: a) std::cin >> x;
    std::vector<int> b = a;
    std::sort(ALL(b));
    int res = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (a[i] > a[j]) res++;
        }
    }
    std::cout << n << " " << res << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
