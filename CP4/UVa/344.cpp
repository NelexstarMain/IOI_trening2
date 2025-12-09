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

std::vector<char> m = {'i', 'v', 'x', 'l', 'c'};
std::vector<std::vector<int>> prec(100, std::vector<int>(5, 0));

void precompute() {
    for (int i = 0; i < 100; i++) {
        std::vector<int> z(5);
        int c = i+1;
        while (c > 0) {
            if (c >= 100) {
                c -= 100;
                z[4]++;
            } else if (c >= 90) {
                c -= 90;
                z[4]++;
                z[2]++;
            } else if (c >= 50) {
                c -= 50;
                z[3]++;
            } else if (c >= 40) {
                c -= 40;
                z[2]++;
                z[3]++;
            } else if (c >= 10) {
                c -= 10;
                z[2]++;
            } else if (c >= 9) {
                c -= 9;
                z[2]++;
                z[0]++;
            } else if (c >= 5) {
                c -= 5;
                z[1]++;
            } else if (c >= 4) {
                c -= 4;
                z[1]++;
                z[0]++;
            } else if (c >= 1) {
                c--;
                z[0]++;
            }
        }
        if (i > 0) {
            for (int j = 0; j < 5; j++) {
                prec[i][j] = z[j] + prec[i-1][j];
            }
        } else {
            prec[i] = z;
        }
    }
}

bool solve() {
    //1: 1 i, 0 v, 0 x, 0 l, 0 c
    int n; std::cin >> n;
    if (n == 0) return false;
    std::vector<int> curr = prec[n-1];
    std::cout << n << ": ";
    for (int i = 0; i < 5; i++) {
        std::cout << curr[i] << " " << m[i] << ((i == 4) ? "\n": ", ");
    }
    return true;
}

int main() {
    fast_io();
    precompute();
    while (solve());
    return 0;
}
