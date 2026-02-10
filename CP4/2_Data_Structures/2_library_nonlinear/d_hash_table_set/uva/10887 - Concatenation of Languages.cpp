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
    int n, k; std::cin >> n >> k;
    std::cin.ignore();
    std::vector<std::string> A(n); 
    for (int i = 0; i < n; ++i) std::getline(std::cin, A[i]);
    
    std::vector<std::string> B(k); 
    for (int i = 0; i < k; ++i) std::getline(std::cin, B[i]);

    std::unordered_set<std::string> C;
    for (auto x: A) {
        for (auto y: B) {
            C.insert(x+y);
        }
    }
    std::cout << "Case " << z << ": " << SIZE(C) << "\n";
}

int main() {
    fast_io();
    int T; std::cin >> T;
    int z = 0;
    while (T--) solve(++z);
    return 0;
}
