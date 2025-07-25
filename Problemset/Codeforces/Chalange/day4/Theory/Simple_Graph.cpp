#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // For std::find

class SimpleGraph {
public:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

    SimpleGraph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph, ensuring it's simple
    void addEdge(int u, int v) {
        if (u == v) {
            std::cout << "Błąd: Nie można dodać pętli (krawędzi od wierzchołka do siebie samego).\n";
            return;
        }
        
        for (int neighbor : adj[u]) {
            if (neighbor == v) {
                std::cout << "Błąd: Krawędź między " << u << " a " << v << " już istnieje.\n";
                return;
            }
        }

        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected simple graph
    }

    // Function to print the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "Lista sąsiedztwa wierzchołka " << v << ":\n ";
            for (int neighbor : adj[v]) {
                std::cout << "-> " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SimpleGraph g(4); // Create a simple graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 0); // This will show an error (loop)
    g.addEdge(0, 1); // This will show an error (multiple edge)
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printGraph();
    return 0;
}