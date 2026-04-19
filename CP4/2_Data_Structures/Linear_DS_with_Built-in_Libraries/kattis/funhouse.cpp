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

void solve_room(std::vector<std::vector<char>>& grid, int height, int width, int startX, int startY) {
    int dx = 0, dy = 0;
    if (startX == 0) dx = 1;    
    else if (startX == height - 1) dx = -1; 
    else if (startY == 0) dy = 1; 
    else if (startY == width - 1) dy = -1; 

    int curX = startX + dx;
    int curY = startY + dy;
    while (grid[curX][curY] != 'x') {
        char cell = grid[curX][curY];
        
        if (cell == '/') {
            int temp = dx;
            dx = -dy;
            dy = -temp;
        } 
        else if (cell == '\\') {
            int temp = dx;
            dx = dy;
            dy = temp;
        }
        curX += dx;
        curY += dy;
    }
    grid[curX][curY] = '&';
}

void solve() {
    int x, y; 
    int count = 1;
    while (std::cin >> x >> y && x != 0 && y != 0) {
        std::vector<std::vector<char>> m(y, std::vector<char>(x, '.')); 
        std::pair<int, int> s;
        for (int i = 0; i < y; i++) {
            std::string c; std::cin >> c;
            for (int j = 0; j < x; j++) {
                if (c[j] == '*') s = {i, j};
                m[i][j] = c[j];
            }
        }
        solve_room(m, x, y, s.F, s.S);
        std::cout << "HOUSE " <<  count << "\n";
        for (int i = 0; i < y; i++) {
            std::string c = "";
            for (int j = 0; j < x; j++) {
                char n = m[i][j];
                c += n;
            }
            std::cout << c << "\n";
            
        }
        count++;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
