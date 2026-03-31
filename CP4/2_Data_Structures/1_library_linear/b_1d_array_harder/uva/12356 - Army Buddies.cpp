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
    int S, B;
    while (std::cin >> S >> B && S) {
        int prev[100050], next[100050];
        for (int i = 0; i < S; i++) {
            next[i] = (i+1);
            prev[i] = (i-1);
        }
        prev[0] = -1;
        next[S-1] = -1;
        while (B--) {
            int L, R;
            std::cin >> L >> R;
            L--, R--;
            int left = prev[L];
            int right = next[R];
            if (left == -1) std::cout << "* ";
            else {
                next[left] = right;
                std::cout << left + 1 << " ";
            }
            if (right == -1) std::cout << "*\n";
            else {
                prev[right] = left;
                std::cout << right + 1 << "\n";
            }
        }
        std::cout << "-\n";
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
