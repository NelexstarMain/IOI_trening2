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
    int a, b, c; std::cin >> a >> b >> c;
    std::vector<std::vector<int>> board(a, std::vector<int>(b, -1));
    for (int i = 0; i < a; i++) {
        std::string s; std::cin >> s;
        for (int j = 0; j < b; j++) {
            if (s[j] == 'R') board[i][j] = 0;
            else if (s[j] == 'S') board[i][j] = 1;
            else if (s[j] == 'P') board[i][j] = 2;
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int day = 0; day < c; day++) {
        std::vector<std::vector<int>> boardcopy = board;
        for (int x = 0; x < b; x++) {
            for (int y = 0; y < a; y++) {
                for (int z = 0; z < 4; z++) {
                    if (0 <= x+dx[z] && x+dx[z] < b && 0 <= y+dy[z] && y+dy[z] < a) {
                        int xn = x+dx[z] , yn = y+dy[z];
                        int nv = board[yn][xn];
                        int ov = board[y][x];
                        if (ov == 0 && nv == 1 || ov == 1 && nv == 2 || ov == 2 && nv == 0) {
                            boardcopy[yn][xn] = ov;
                        }
                    }
                }
            }
        }
        board = boardcopy;
    }
    for (int i = 0; i < a; i++) {
        std::string s = "";
        for (int j = 0; j < b; j++) {
            if (board[i][j] == 0) s += 'R';
            else if (board[i][j] == 1) s += 'S';
            else if (board[i][j] == 2) s += 'P';
        }
        std::cout << s << "\n";
    }
    std::cout << "\n";
}
int main() {
    fast_io();
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}
