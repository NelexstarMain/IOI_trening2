#include <iostream>
#include <vector>
#include <list>
#include <utility> 

class WeightedGraph {
public:
    int V; 
    // Adjacency list where each element is a list of pairs (neighbor, weight)
    std::vector<std::list<std::pair<int, int>>> adj;

    WeightedGraph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); 
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "Lista sąsiedztwa wierzchołka " << v << ":\n ";
            for (const auto& edge : adj[v]) {
                std::cout << "-> " << edge.first << " (waga: " << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    WeightedGraph g(5); 
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);
    g.printGraph();
    return 0;
}