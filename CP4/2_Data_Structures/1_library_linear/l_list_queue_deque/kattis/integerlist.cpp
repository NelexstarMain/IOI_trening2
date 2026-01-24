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
    std::string code; std::cin >> code;
    int n; std::cin >> n;
    std::string list; std::cin >> list;
    std::stringstream ss(list);
    std::vector<std::string> A;
    std::string item;

    while (std::getline(ss, item, ',')) {
        A.PB(item);
    }

    if (n > 0) { A[0] = A[0].substr(1, SIZE(A[0])-1); A[n-1] = A[n-1].substr(0, SIZE(A[n-1])-1);}
    else { A[0] = ""; }
    // for (auto x: A) std::cout << x << " ";
    // std::cout <<"\n";
    int D = 1, F = 0, S = 0, Sum = 0;
    for (char x: code) {
        if (x == 'R') D *= -1;
        else {
            if (D == 1) F++;
            else S++;
            Sum++;
        }
        if (Sum > n) {
            std::cout << "error\n";
            return;
        }
    }
    std::cout << "[";
    if (D == 1) {
        for (int i = F; i < n-S; i++) {
            std::cout << A[i];
            if (i < n-S-1) std::cout << ',';
        }
    } else {
        for (int i = n-S-1; i >= F; i--) {
            std::cout << A[i];
            if (i > F) std::cout << ',';
        }
    }
    
    std::cout << "]\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
