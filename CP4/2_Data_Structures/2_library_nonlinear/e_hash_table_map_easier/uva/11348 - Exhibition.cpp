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

void solve(int z) {
    int n; std::cin >> n;
    std::vector<std::set<int>> A;
    std::map<int, int> C;
    for (int i = 0; i < n; i++) {
        int m; std::cin >> m;
        std::set<int> QR;
        for (int k = 0; k < m; k++) {
            int curr; std::cin >> curr;
            QR.insert(curr);
        }
        for (int x: QR) C[x]++;
        // std::vector<int> B(m); for (int& x: B) std::cin >> x;
        A.PB(QR);
    }
    std::cout << "Case " << z << ":";
    std::vector<int> Counts(n);
    int uniq = 0;
    for (auto [k, v]: C) if (v == 1) uniq++;
    for (int i = 0; i < n; i++) {
        int co = 0;
        for (int x: A[i]) if (C[x] == 1) co++;
        if (uniq > 0) std::cout << " " << std::fixed << std::setprecision(6) <<(double)((co*1.0/uniq)*100) << "%";
        else std::cout << " 0.000000%";
    }
    std::cout << "\n";

}

int main() {
    fast_io();
    int T; std::cin >> T;
    int z = 1;
    while (T--) solve(z++);
    return 0;
}
