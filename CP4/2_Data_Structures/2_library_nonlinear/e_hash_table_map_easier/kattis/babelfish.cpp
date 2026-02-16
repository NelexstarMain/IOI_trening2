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
    std::unordered_map<std::string, std::string> A;
    std::string l;
    while (std::getline(std::cin, l) && l != "") {
        std::stringstream ss(l);
        std::string f, s; ss >> f >> s;
        A[s] = f;
    }

    while (std::getline(std::cin, l) && !l.empty()) {
        std::stringstream ss(l);
        std::string f; ss >> f;
        // std::cout << f << "\n";
        if (A.find(f) != A.end()) std::cout << A[f];
        else std::cout << "eh";
        std::cout << "\n";
    }

}

int main() {
    fast_io();
    solve();
    return 0;
}
