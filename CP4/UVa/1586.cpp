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
std::unordered_map<char, double> costs = {{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};
void solve() {
    std::string s; std::cin >> s;
    double res = 0.0;
    for (int i = 0; i < s.size();) {
        char curr = s[i];
        int j = i;
        if (!std::isdigit(curr)) {
            if (i+1 < s.size() && std::isdigit(s[i+1])) {
                int num = 0;
                j++;
                while (std::isdigit(s[j]) && j < s.size()) {
                    num *= 10;
                    num += s[j] - '1' + 1;
                    j++;
                }
                res += num * 1.0 * costs[curr];
            } else {
                    res += 1.0 * costs[curr];
                    j++;
                }
        } 
        i = j;
    }
    std::cout << std::fixed << std::setprecision(3) << res << "\n";
}
    


int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
