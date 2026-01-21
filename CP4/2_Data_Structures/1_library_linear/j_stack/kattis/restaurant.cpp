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
    int n;
    while (std::cin >> n && n > 0) {
        int F = 0, S = 0;
        for (int i = 0; i < n; i++) {
            std::string na; std::cin >> na;
            int m; std::cin >> m;
            if (na == "DROP") {
                std::cout << "DROP 2 " << m << "\n"; 
                S = S + m;
            } else if (na == "TAKE") {
                if (F < m) {
                    if (F > 0) std::cout << "TAKE 1 " << F << "\n";
                    std::cout << "MOVE 2->1 " << S << "\n";
                    std::cout << "TAKE 1 " << m-F << "\n";
                    F += S-m;
                    S = 0;

                } else {
                    std::cout << "TAKE 1 " << m << "\n";
                    F -= m;
                }
                
                // std::cout << F << "\n";
            }
        }   
        std::cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
