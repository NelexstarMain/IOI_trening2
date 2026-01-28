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
    std::string s;
    while (std::cin >> s) {
        bool valid = true;
        int L = SIZE(s), c = 0;
        std::vector<int> A(L, 0);
        for (int i = 0; i < L; i++) {
            int n = s[i]-'0';
            int r = ((i+n)%L);
            if (A[r] == 0) A[r]++;
            else valid = false;
            c += n;
        }
        std::cout << s;
        if (c%L!=0) std::cout << ": invalid # of balls";
        else if (!valid) std::cout << ": invalid pattern";
        else std::cout << ": valid with " << (int)(c/L) << " balls";
        std::cout << "\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
