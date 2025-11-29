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
    std::vector<std::vector<char>> board(8, std::vector<char>(8, '.'));
    for (int i = 0; i < 8; i++) {
        std::string s; std::cin >> s;
        for (int j = 0; j < 8; j++) {
            board[j][i] = s[j];
        }
    }
    std::string path; std::cin >> path;

    std::vector<pii> dir = {{1,0}, {0,-1}, {-1,0}, {0,1}};
    int x = 0, y = 7;
    int currdir = 0;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'F') { {
            if (0 <= x + dir[currdir].first && 0 <= y + dir[currdir].second && x + dir[currdir].first < 8 && y + dir[currdir].second < 8) {
                if (board[x + dir[currdir].first][y + dir[currdir].second] != '.' && board[x + dir[currdir].first][y + dir[currdir].second] != 'D') {
                    std::cout << "Bug!\n";
                    return;
                } else {
                    x += dir[currdir].first;
                    y += dir[currdir].second;
                }
            } else {
                std::cout << "Bug!\n";
                return;
            }
        }
            
        } else if (path[i] == 'X') {
            if (0 <= x + dir[currdir].first && 0 <= y + dir[currdir].second && x + dir[currdir].first < 8 && y + dir[currdir].second < 8) {
                if (board[x + dir[currdir].first][y + dir[currdir].second] != 'I') {
                    std::cout << "Bug!\n";
                    return;
                } else {
                    board[x + dir[currdir].first][y + dir[currdir].second] = '.';
                }
            } else {
                std::cout << "Bug!\n";
            }   
            
        }
        else if (path[i] == 'L') {
            currdir = (currdir+1)%4;
        } else if (path[i] == 'R') {
            currdir = (currdir+3)%4;
        } else {
            std::cout << "Bug!\n";
            return;
        }
    }
    if (board[x][y] == 'D') {
        std::cout << "Diamond!\n";
    } else {
        std::cout << "Bug!\n";
    }


}

int main() {
    fast_io();
    solve();
    return 0;
}
