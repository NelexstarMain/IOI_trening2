#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n+1);
        for(int i=0;i<n-1;i++){
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==2){
            cout << 0 << '\n';
            continue;
        }

        auto bfs = [&](int src){
            vector<int> dist(n+1, -1), parent(n+1, -1);
            queue<int> q;
            q.push(src);
            dist[src]=0;
            while(!q.empty()){
                int v=q.front(); q.pop();
                for(int to: g[v]){
                    if(dist[to]==-1){
                        dist[to]=dist[v]+1;
                        parent[to]=v;
                        q.push(to);
                    }
                }
            }
            int far = src;
            for(int i=1;i<=n;i++){
                if(dist[i] > dist[far]) far = i;
            }
            return pair<int, vector<int>>(far, parent);
        };

        // pierwszy BFS z 1 (dowolnego wierzchołka) -> A
        int any = 1;
        auto res1 = bfs(any);
        int A = res1.first;

        // drugi BFS z A -> B, plus parenty
        auto res2 = bfs(A);
        int B = res2.first;
        vector<int> parent = res2.second;

        // odbuduj ścieżkę A->B
        vector<int> path;
        int cur = B;
        while(cur != -1){
            path.push_back(cur);
            if(cur == A) break;
            cur = parent[cur];
        }
        // path teraz A..B w odwrotnej kolejności? Faktycznie path zawiera B..A, ale nie musimy odwracać do liczenia
        // policz ile wierzchołków na ścieżce ma stopień > 2
        int cnt = 0;
        vector<char> onPath(n+1, 0);
        for(int v: path) onPath[v] = 1;
        for(int v: path){
            if((int)g[v].size() > 2) cnt++;
        }

        if(cnt <= 1) cout << 0 << '\n';
        else cout << (cnt - 1) << '\n';
    }
    return 0;
}
