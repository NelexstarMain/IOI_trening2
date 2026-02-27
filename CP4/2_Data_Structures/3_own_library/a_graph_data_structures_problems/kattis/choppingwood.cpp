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

// 6
// 5
// 1
// 1
// 2
// 2
// 7

void solve() {
    int n; std::cin >> n;
    std::unordered_map<int, int> A;
    std::vector<int> C;
    for (int i = 0; i < n; i++) {
        int curr; std::cin >> curr;
        A[curr]++;
        C.PB(curr);
    }
    std::priority_queue<int> B;
    if (C[SIZE(C)-1] != n+1) {
        std::cout << "Error\n";
        return;
    }
    for (int i = 1; i <= n+1; i++) if (A.find(i) == A.end()) B.push(-i);
    for (int x: C) {
        if (B.empty()) {
            std::cout << "Error\n";
            return;
        }
        int val = B.top();
        std::cout << -val << "\n";
        B.pop();
        if (A[x] == 1) B.push(-x);
        else A[x]--;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
