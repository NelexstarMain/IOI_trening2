#include <iostream>
#include <vector>
#include <list>

class CompleteGraph {
public:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

    CompleteGraph(int V) {
        this->V = V;
        adj.resize(V);
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) { // Start from i+1 to avoid self-loops and duplicate edges
                adj[i].push_back(j);
                adj[j].push_back(i); // Undirected
            }
        }
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
    CompleteGraph g(5); // Create a complete graph with 5 vertices
    g.printGraph();
    return 0;
}