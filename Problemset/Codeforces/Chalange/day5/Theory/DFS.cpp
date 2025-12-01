#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stack>

using namespace std;

class Graf {
private:
    int V; 
    std::vector<std::list<int>> adj; 

public:
    Graf(int v) : V(v), adj(v) {}

    void dodajKrawedz(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void wyswietl() const {
        for (int i = 0; i < V; ++i) {
            std::cout << i << ": ";
            for (int sasiad : adj[i]) {
                std::cout << sasiad << " ";
            }
            std::cout << "\n";
        }
    }

    int size() const {
        return V;
    }

    const std::list<int>& sasiedzi(int v) const {
        return adj[v];
    }
};


vector<int> DFS(Graf* graf, int start) {
    set<int> visited;
    vector<int> wynik;
    stack<int> stos;

    stos.push(start);

    while (!stos.empty()) {
        int v = stos.top();
        stos.pop();

        if (visited.find(v) == visited.end()) {
            visited.insert(v);
            wynik.push_back(v);


            for (auto it = graf->sasiedzi(v).rbegin(); it != graf->sasiedzi(v).rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    stos.push(*it);
                }
            }
        }
    }

    return wynik;
}

// Przykład użycia
int main() {
    Graf g(6);

    g.dodajKrawedz(0, 1);
    g.dodajKrawedz(0, 2);
    g.dodajKrawedz(1, 3);
    g.dodajKrawedz(2, 3);
    g.dodajKrawedz(3, 4);
    g.dodajKrawedz(4, 5);

    g.wyswietl();

    vector<int> odwiedzone = DFS(&g, 0);
    cout << "DFS od wierzchołka 0:\n";
    for (int v : odwiedzone) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
