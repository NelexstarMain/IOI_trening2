import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Objects; // Dodane dla equals i hashCode w SimpleGraph

public class GraphImplementations {

    // --- Graf Nieskierowany (Undirected Graph) ---
    public static class UndirectedGraph {
        private int V; // Liczba wierzchołków
        private List<List<Integer>> adj; // Lista sąsiedztwa

        public UndirectedGraph(int V) {
            this.V = V;
            adj = new ArrayList<>(V);
            for (int i = 0; i < V; i++) {
                adj.add(new LinkedList<>());
            }
        }

        public void addEdge(int u, int v) {
            adj.get(u).add(v);
            adj.get(v).add(u); // Dla grafów nieskierowanych
        }

        public void printGraph() {
            System.out.println("\n--- Graf Nieskierowany ---");
            for (int v = 0; v < V; v++) {
                System.out.print("Lista sąsiedztwa wierzchołka " + v + ": ");
                for (Integer neighbor : adj.get(v)) {
                    System.out.print("-> " + neighbor);
                }
                System.out.println();
            }
        }
    }

    // --- Graf Skierowany (Directed Graph / Digraph) ---
    public static class DirectedGraph {
        private int V; // Liczba wierzchołków
        private List<List<Integer>> adj; // Lista sąsiedztwa

        public DirectedGraph(int V) {
            this.V = V;
            adj = new ArrayList<>(V);
            for (int i = 0; i < V; i++) {
                adj.add(new LinkedList<>());
            }
        }

        public void addEdge(int u, int v) {
            adj.get(u).add(v); // Tylko w jednym kierunku
        }

        public void printGraph() {
            System.out.println("\n--- Graf Skierowany ---");
            for (int v = 0; v < V; v++) {
                System.out.print("Lista sąsiedztwa wierzchołka " + v + ": ");
                for (Integer neighbor : adj.get(v)) {
                    System.out.print("-> " + neighbor);
                }
                System.out.println();
            }
        }
    }

    // --- Graf Ważony (Weighted Graph) ---
    public static class WeightedGraph {
        private int V; // Liczba wierzchołków
        private List<List<Edge>> adj; // Lista sąsiedztwa z obiektami Edge

        // Klasa wewnętrzna reprezentująca krawędź z wagą
        static class Edge {
            int destination;
            int weight;

            public Edge(int destination, int weight) {
                this.destination = destination;
                this.weight = weight;
            }

            @Override
            public String toString() {
                return "->" + destination + " (waga: " + weight + ")";
            }
        }

        public WeightedGraph(int V) {
            this.V = V;
            adj = new ArrayList<>(V);
            for (int i = 0; i < V; i++) {
                adj.add(new LinkedList<>());
            }
        }

        // Zakładamy nieskierowany graf ważony dla prostoty
        public void addEdge(int u, int v, int weight) {
            adj.get(u).add(new Edge(v, weight));
            adj.get(v).add(new Edge(u, weight));
        }

        public void printGraph() {
            System.out.println("\n--- Graf Ważony ---");
            for (int v = 0; v < V; v++) {
                System.out.print("Lista sąsiedztwa wierzchołka " + v + ": ");
                for (Edge edge : adj.get(v)) {
                    System.out.print(edge + " ");
                }
                System.out.println();
            }
        }
    }

    // --- Graf Prosty (Simple Graph) ---
    public static class SimpleGraph {
        private int V; // Liczba wierzchołków
        private List<List<Integer>> adj; // Lista sąsiedztwa

        public SimpleGraph(int V) {
            this.V = V;
            adj = new ArrayList<>(V);
            for (int i = 0; i < V; i++) {
                adj.add(new LinkedList<>());
            }
        }

        public void addEdge(int u, int v) {
            if (u == v) {
                System.out.println("Błąd: Nie można dodać pętli (krawędzi od wierzchołka do siebie samego).");
                return;
            }

            // Sprawdzamy, czy krawędź już istnieje, aby zapobiec wielokrotnym krawędziom
            if (adj.get(u).contains(v)) {
                System.out.println("Błąd: Krawędź między " + u + " a " + v + " już istnieje.");
                return;
            }

            adj.get(u).add(v);
            adj.get(v).add(u); // Dla nieskierowanego grafu prostego
        }

        public void printGraph() {
            System.out.println("\n--- Graf Prosty ---");
            for (int v = 0; v < V; v++) {
                System.out.print("Lista sąsiedztwa wierzchołka " + v + ": ");
                for (Integer neighbor : adj.get(v)) {
                    System.out.print("-> " + neighbor);
                }
                System.out.println();
            }
        }
    }

    // --- Graf Pełny (Complete Graph) ---
    public static class CompleteGraph {
        private int V; // Liczba wierzchołków
        private List<List<Integer>> adj; // Lista sąsiedztwa

        public CompleteGraph(int V) {
            this.V = V;
            adj = new ArrayList<>(V);
            for (int i = 0; i < V; i++) {
                adj.add(new LinkedList<>());
            }

            // Automatycznie dodajemy wszystkie krawędzie, aby stworzyć graf pełny
            for (int i = 0; i < V; i++) {
                for (int j = i + 1; j < V; j++) { // Zaczynamy od i+1, aby uniknąć pętli i duplikatów
                    adj.get(i).add(j);
                    adj.get(j).add(i); // Nieskierowany
                }
            }
        }

        public void printGraph() {
            System.out.println("\n--- Graf Pełny ---");
            for (int v = 0; v < V; v++) {
                System.out.print("Lista sąsiedztwa wierzchołka " + v + ": ");
                for (Integer neighbor : adj.get(v)) {
                    System.out.print("-> " + neighbor);
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        // Przykład użycia Grafu Nieskierowanego
        UndirectedGraph ug = new UndirectedGraph(5);
        ug.addEdge(0, 1);
        ug.addEdge(0, 4);
        ug.addEdge(1, 2);
        ug.addEdge(1, 3);
        ug.addEdge(1, 4);
        ug.addEdge(2, 3);
        ug.addEdge(3, 4);
        ug.printGraph();

        // Przykład użycia Grafu Skierowanego
        DirectedGraph dg = new DirectedGraph(5);
        dg.addEdge(0, 1);
        dg.addEdge(0, 4);
        dg.addEdge(1, 2);
        dg.addEdge(1, 3);
        dg.addEdge(1, 4);
        dg.addEdge(2, 3);
        dg.addEdge(3, 4);
        dg.printGraph();

        // Przykład użycia Grafu Ważonego
        WeightedGraph wg = new WeightedGraph(5);
        wg.addEdge(0, 1, 10);
        wg.addEdge(0, 4, 20);
        wg.addEdge(1, 2, 30);
        wg.addEdge(1, 3, 40);
        wg.addEdge(1, 4, 50);
        wg.addEdge(2, 3, 60);
        wg.addEdge(3, 4, 70);
        wg.printGraph();

        // Przykład użycia Grafu Prostego
        SimpleGraph sg = new SimpleGraph(4);
        sg.addEdge(0, 1);
        sg.addEdge(0, 2);
        sg.addEdge(0, 0); // Spowoduje błąd (pętla)
        sg.addEdge(0, 1); // Spowoduje błąd (wielokrotna krawędź)
        sg.addEdge(1, 2);
        sg.addEdge(2, 3);
        sg.printGraph();

        // Przykład użycia Grafu Pełnego
        CompleteGraph cg = new CompleteGraph(5);
        cg.printGraph();
    }
}