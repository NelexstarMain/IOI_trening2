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
    std::string name, day, month, year;
    std::vector<std::vector<std::string>> a;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> day >> month >> year;
        a.PB({name, day, month, year});
    }
    std::sort(ALL(a), [](std::vector<std::string>& a, std::vector<std::string>& b){
        if (a[3] != b[3]) return std::stoi(a[3]) < std::stoi(b[3]);
        else if (a[2] != b[2]) return std::stoi(a[2]) < std::stoi(b[2]);
        else if (a[1] != b[1]) return std::stoi(a[1]) < std::stoi(b[1]);
    });
    std::cout << a[n-1][0] << "\n" << a[0][0] << "\n"; 
}

int main() {
    fast_io();
    solve();
    return 0;
}
