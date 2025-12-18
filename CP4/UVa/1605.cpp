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

std::vector<char> cou = {
    'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 
    'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 
    'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 
    'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 
    'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y'
};

void solve() {
    int n;
    while (cin >> n) {

        
        cout << n << " " << n << " " << 2 << "\n";
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                cout << cou[i];
            }
            cout << "\n";
            for (int i = 0; i < n; i++) {
                cout << cou[j];
            }
            cout << "\n"; 
            if (j < n - 1) {
                cout << "\n"; 
            }
        }
    }
}


int main() {
    fast_io();
    solve();
    return 0;
}
