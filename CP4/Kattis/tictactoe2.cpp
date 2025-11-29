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
    int xcount = 0, ocount = 0;
    std::vector<std::vector<int>> board(3, std::vector<int>(3, -1));
    for (int i = 0; i < 3; i++) {
        std::string s; std::cin >> s;
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'X') {
                xcount++;
                board[i][j] = 0;
            } else if (s[j] == 'O') {
                ocount++;
                board[i][j] = 1;
            }
        }
    }
    int xwins = 0, owins = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][2] == board[i][0] && board[i][1] == board[i][2] && board[i][1] == 0) {
            xwins++;
        }
        if (board[i][0] == board[i][1] && board[i][2] == board[i][0] && board[i][1] == board[i][2] && board[i][1] == 1) {
            owins++;
        }
        if (board[0][i] == board[1][i] && board[2][i] == board[0][i] && board[1][i] == board[2][i] && board[1][i] == 0) {
            xwins++;
        }
        if (board[0][i] == board[1][i] && board[2][i] == board[0][i] && board[1][i] == board[2][i] && board[1][i] == 1) {
            owins++;
        }
    }
    if (board[0][0] == board[1][1] && board[2][2] == board[0][0] && board[1][1] == board[2][2] && board[1][1] == 0) {
        xwins++;
    } 
    if (board[2][0] == board[1][1] && board[0][2] == board[2][0] && board[1][1] == board[0][2] && board[1][1] == 0) {
        xwins++;
    }
    if (board[0][0] == board[1][1] && board[2][2] == board[0][0] && board[1][1] == board[2][2] && board[1][1] == 1) {
        owins++;
    } 
    if (board[2][0] == board[1][1] && board[0][2] == board[2][0] && board[1][1] == board[0][2] && board[1][1] == 1) {
        owins++;
    }
    if ((owins == 0 || xwins == 0) && (xcount - ocount == 0 || xcount - ocount == 1)) {
        if (xwins > 0 && (xcount-ocount) == 1) {
            std::cout << "yes\n";
        } else if (owins == 1 && (xcount-ocount) == 0) {
            std::cout << "yes\n";
        } else if (owins+xwins == 0) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
        
    } else {
        std::cout << "no\n";
    }

}

int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
