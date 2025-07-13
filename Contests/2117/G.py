def add_edge(adj, u, v, w):
    if u not in adj:
        adj[u] = []
    adj[u].append((v, w))

    if v not in adj:
        adj[v] = []
    adj[v].append((u, w))

def get_neighbors(adj, vertex):
    return adj.get(vertex, [])

if __name__ == "__main__":
    graph_adj = {}
