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
    int n, b; std::cin >> n >> b;
    std::vector<int> A(n); for (int& x: A) std::cin >> x;
    int index, bilans = 0, count = 1; for (int i = 0; i < n; i++) if (A[i] == b) index = i;
    std::map<int, int> C;
    for (int i = index-1; i >= 0; i--) {
        if (A[i] < b) bilans--;
        else bilans++;
        if (bilans == 0) count++;
        C[bilans]++;
    }
    bilans = 0;
    for (int i = index+1; i < n; i++) {
        if (A[i] < b) bilans--;
        else bilans++;
        if (bilans == 0) count++;
        count += C[-bilans];
    }
    std::cout << count << "\n";
}

int main() {
    fast_io();
    solve();
    return 0;
}
