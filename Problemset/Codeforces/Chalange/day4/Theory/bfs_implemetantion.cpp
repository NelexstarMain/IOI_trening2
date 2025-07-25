#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

class Graph {
private:
    std::vector<std::vector<int>> abj;
    int vertices;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        abj.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int a, int b) {
        abj[a][b] = 1;
        abj[b][a] = 1;
    }

    std::vector<int> neighbours(int v) {
        std::vector<int> result;
        for (int i = 0; i < vertices; ++i) {
            if (abj[v][i] == 1)
                result.push_back(i);
        }
        return result;
    }

    int BFS(int start, int end) {
        std::vector<bool> visited(vertices, false);
        std::vector<int> distance(vertices, -1);
        std::queue<int> q;

        visited[start] = true;
        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == end)
                return distance[end];

            for (int neighbor : neighbours(curr)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        return -1; 
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    std::cout << "Najkrótsza ścieżka z 0 do 5: " << g.BFS(0, 5) << "\n";

    return 0;
}
