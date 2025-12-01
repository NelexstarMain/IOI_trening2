#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<vector<char>> grid(n+1, vector<char>(n+1));
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) {
            grid[i][j] = s[j-1];
        }
    }
    
    vector<vector<int>> dist(n+1, vector<int>(n+1, -1));
    dist[1][1] = 0;
    queue<pair<int, int>> qu;
    qu.push({1, 1});
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while(!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                qu.push({nx, ny});
            }
        }
    }
    
    vector<vector<bool>> is_fort(n+1, vector<bool>(n+1, false));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(grid[i][j] == 'F') {
                is_fort[i][j] = true;
            }
        }
    }
    
    const int MAXD = 2005;
    vector<int> freq(MAXD + 1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(is_fort[i][j]) {
                int d = dist[i][j];
                freq[d]++;
            }
        }
    }
    
    auto compute = [&]() -> int {
        int max_T = 0;
        int current_i = 1;
        for(int dd = MAXD; dd >= 0; dd--) {
            int cnt = freq[dd];
            if(cnt > 0) {
                int this_max = dd + current_i + cnt - 2;
                if(this_max > max_T) max_T = this_max;
                current_i += cnt;
            }
        }
        return max_T;
    };
    
    cout << compute() << '\n';
    
    for(int iq = 0; iq < q; iq++) {
        int x, y;
        cin >> x >> y;
        int d = dist[x][y];
        bool was = is_fort[x][y];
        is_fort[x][y] = !was;
        int delta = is_fort[x][y] ? 1 : -1;
        freq[d] += delta;
        cout << compute() << '\n';
    }
    
    return 0;
}