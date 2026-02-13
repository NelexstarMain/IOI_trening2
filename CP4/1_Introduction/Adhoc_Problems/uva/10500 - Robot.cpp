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
    int a, b; 
    while (std::cin >> a >> b && (a + b) > 0) {
        int x, y; 
        cin >> x >> y;
        x--; y--;
        vector<vector<char>> oldmap(a, vector<char>(b));
        vector<vector<char>> newmap(a, vector<char>(b, '?')); 

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> oldmap[i][j];
            }
        }
        int moves = 0;
        newmap[x][y] = '0';
        while (true) {
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            int nextx = -1, nexty = -1;
            
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 0 && newx < a && newy >= 0 && newy < b) {
                    if (oldmap[newx][newy] == '0') {
                        if (nextx == -1) {
                            nextx = newx;
                            nexty = newy;
                        }
                        newmap[newx][newy] = '0';
                    } else if (oldmap[newx][newy] == 'X') {
                        newmap[newx][newy] = 'X';
                    }
                }
            }
            if (nextx == -1 && nexty == -1) break;
            oldmap[x][y] = 'V'; 
            x = nextx;
            y = nexty;
            moves++;

        }
        std::cout << "\n";
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) std::cout << "|---";
            std::cout << "|\n";
            for (int j = 0; j < b; j++) {
                std::cout << "| " << newmap[i][j] << " ";
            }
            std::cout << "|\n";
        }
        for (int j = 0; j < b; j++) std::cout << "|---";
        std::cout << "|\n\n";
        std::cout << "NUMBER OF MOVEMENTS: " << moves << "\n";
    }
    
    
}

int main() {
    fast_io();
    solve();
    return 0;
}
