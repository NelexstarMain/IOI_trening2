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
    int n, m; std::cin >> n >> m;
    std::map<std::string, int> A;
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        double num; std::cin >> num;
        A[s] = (int)(10.0*num+0.5);
    }
    std::cin.ignore();
    for (int i = 0; i < m; i++) {
        std::string evu; std::getline(std::cin, evu);
        std::stringstream ss(evu);
        double sum = 0.0;
        std::string f, s;
        do {
            ss >> f >> s;
            sum += A[f];
        } while (s == "+");
        std::cout << "Guess #" << i+1 << " was ";
        double res; ss >> res;
        int r = (int)(10.0*res+0.5);
        // std::cout << sum << "\n";
        if ((s == "<" && sum < r) || (s == "<=" && sum <= r) || (s == "=" && sum == r) || (s == ">=" && sum >= r) || (s == ">" && sum > r)) std::cout << "correct.";
        else std::cout << "incorrect.";
        std::cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
