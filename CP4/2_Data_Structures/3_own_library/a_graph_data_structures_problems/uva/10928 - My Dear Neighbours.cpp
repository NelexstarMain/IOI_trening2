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
    int p; std::cin >> p;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string l;
    int m = INF;
    std::vector<int> A;
    for (int i = 0; i < p; i++) {
        std::getline(std::cin, l);
        std::stringstream ss(l);
        int curr, timer = 0; 
        while (ss >> curr) timer++;
        if (timer < m) {
            A.clear(); 
            m = timer;
        }
        if (timer == m) A.PB(i+1);
    }

    std::cout << A[0];
    for (int i = 1; i < SIZE(A); i++) std::cout << " " << A[i];
    std::cout << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
