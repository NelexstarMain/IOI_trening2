#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

int n, m;
vector<string> forest;

const int INF = 1e9;
vector<vector<int>> distE;

vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

bool can_move(char c) {
    return (isdigit(c) || c == 'S' || c == 'E');
}

    vector<vector<int>> bfs(pair<int,int> start) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();

        for (auto [dx,dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >=0 && nx < n && ny >= 0 && ny < m) {
                if (can_move(forest[nx][ny]) && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    forest.resize(n);
    for (auto& row : forest) cin >> row;

    pair<int,int> start{-1,-1}, end{-1,-1};
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (forest[i][j] == 'S') start = {i,j};
            if (forest[i][j] == 'E') end = {i,j};
        }
    }

    vector<vector<int>> distS = bfs(start);
    distE = bfs(end);

    int shortest = distS[end.first][end.second];


    int sum_digits = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (isdigit(forest[i][j])) {
                if (distE[i][j] != -1 && distE[i][j] <= shortest) {
                    sum_digits += (forest[i][j] - '0');
                }
            }
        }
    }

    cout << sum_digits << "\n";

    return 0;
}
