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

unordered_map<int, int> starsToGet = {
    {25, 2}, {24, 2}, {23, 2}, {22, 2}, {21, 2},
    {20, 3}, {19, 3}, {18, 3}, {17, 3}, {16, 3},
    {15, 4}, {14, 4}, {13, 4}, {12, 4}, {11, 4},
    {10, 5}, {9, 5}, {8, 5}, {7, 5}, {6, 5},
    {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}
};

void solve() {
    std::string s; std::cin >> s;
    int rank = 25;
    int stars = 0;
    int passa = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') {
            passa = 0;
            if (rank <= 19) {
                if (stars == 0) {
                    rank++;
                    stars = starsToGet[rank]-1;
                } else {
                    stars--;
                }
            }
        } else {
            passa++;
            stars++;
            if (rank >= 6 && passa >= 3) {
                stars++;
            }
            if (stars > starsToGet[rank]) {
                stars -= starsToGet[rank];
                rank--;
            }
            if (rank == 0) {
                break;
            }
        }
    }
    std::cout << ((rank == 0) ? "Legend" : std::to_string(rank)) << "\n";
    return;

}

int main() {
    fast_io();
    solve();
    return 0;
}
