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

bool sorted(std::vector<int> a) {
    bool valid = true;
    for (int i = 0; i < 5; i++) {
        if (a[i] != i+1) valid = false;
    }
    return valid;
}

void solve() {
    std::vector<int> a(5); for (int& x: a) std::cin >> x;
    while (!sorted(a)) {
        for (int i = 1; i < 5; i++) {
            if (a[i] < a[i-1]) {
                int f=a[i-1], s=a[i];
                a[i-1] = s;
                a[i] = f;
                for (int x: a) std::cout << x << " ";
                std::cout << "\n";
            }
        }
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
