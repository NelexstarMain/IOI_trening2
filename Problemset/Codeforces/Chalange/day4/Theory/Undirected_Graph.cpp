#include <iostream>
#include <vector>
#include <list>

class UndirectedGraph {
    public:
        int V; 
        std::vector<std::list<int>> adj; 

        UndirectedGraph(int V) {
            this->V = V;
            adj.resize(V);
        }


        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

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
    UndirectedGraph g(5); 
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}
