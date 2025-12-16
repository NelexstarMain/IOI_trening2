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
    std::string line; 
    while (std::getline(std::cin, line)) {
        double sums = 0.0;
        int count = 0;
        std::stringstream ss(line);
        std::string curr;
        std::string name = "";
        while (ss >> curr) {
            if (!std::isdigit(curr[0])) {
                name = name + curr + " ";
            } else {
                sums += std::stod(curr);
                count++;
            }
        }
        std::cout << std::fixed << std::setprecision(6) << (double)(sums/(count*1.0)) << " " << name << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
