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

    // std::map<int, int> A;
    // std::unordered_set<int> B;
    // std::vector<int> C;
    // for (int i = 0; i < n; i++) { int c; std::cin >> c; C.PB(c); B.insert(c); }
    // int L = 0, R = 0, M = 0;
    // A[C[L]]++;
    // while (R < SIZE(C)) {
    //     while (SIZE(A) == SIZE(B)) {
    //         M = std::min(M, R-L); L++;
    //         A[C[L]]--;
    //         if (A[C[L]] == 0) A.erase(C[L]);
    //     }
    //     if (SIZE(A) < SIZE(B)) {
    //         R++; if (R < SIZE(C)) A[C[R]]++;
    //     } 
    // }
    // std::cout << M << "\n";

    std::unordered_map<int, int> A;
    int L = 0, M = 0;
    std::vector<int> B(n); for (int& x: B) std::cin >> x;
    for (int i = 0; i < n; i++) {
        if (A.count(B[i])) { while (B[L] != B[i]) { A.erase(B[L]); L++; } L++;         }

        A[B[i]]++; 
        M = std::max(M, SIZE(A));

    }
    std::cout << M << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
