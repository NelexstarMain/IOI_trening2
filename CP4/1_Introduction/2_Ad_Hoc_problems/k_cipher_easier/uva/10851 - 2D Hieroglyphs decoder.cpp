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
    std::cin >> s;
    if (s.size() <= 2) {
        for(int i=0; i<10; i++) std::cin >> s;
        std::cout << "\n";
        return;
    }
    std::vector<int> nums(s.size()-2, 0);
    for (int i = 0; i < 8; i++) {
        std::cin >> s;
        for (int j = 1; j < s.size()-1; j++) {
            if (s[j] == '\\') nums[j-1] += (1 << i);
        }
    }
    std::cin >> s;
    for (int i = 0; i < SIZE(nums); i++) {
        std::cout << (char)nums[i];
    }
    std::cout << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
