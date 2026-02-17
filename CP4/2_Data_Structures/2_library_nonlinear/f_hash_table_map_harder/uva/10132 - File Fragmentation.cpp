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

void solve(bool valid) {
    std::string l;
    std::vector<std::string> A; int sum = 0, maxim = 0;
    while (std::getline(std::cin, l) && l != "") { A.PB(l); sum += SIZE(l); }
    int N = SIZE(A) / 2;
    int target_len = sum / N;
    std::map<std::string, int> B;
    for (int i = 0; i < SIZE(A); i++) {
        for (int j = 0; j < SIZE(A); j++) {
            std::string curr = A[i] + A[j];
            if (SIZE(curr) == target_len && i!=j) { B[curr]++; maxim = std::max(maxim, B[curr]); }
        }
    }
    if (!valid) std::cout << "\n";
    for (auto [k, v]: B) if (v == maxim) { std::cout << k << "\n"; return; }

}

int main() {
    fast_io();
    int T; std::cin >> T;
    std::cin.ignore();
    std::string dummy; 
    std::getline(std::cin, dummy);
    for (int i = 0; i < T; i++) {
        solve(i == 0);
    }
    return 0;
}
