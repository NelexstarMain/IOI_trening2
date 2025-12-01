class Grafs:
    def __init__(self, vertexes) -> None:
        self.adj: list[list[int]] = [[] for _ in range(vertexes)]
        self.ver = vertexes

    def add_edge(self, a, b) -> None:
        self.adj[a].append(b)
        self.adj[b].append(a)

    def draw_graph(self) -> str:
        lines = []
        width = len(str(self.ver - 1))
        lines.append("╔══════════════════════╗")
        lines.append("║   Lista sąsiedztwa   ║")
        lines.append("╚══════════════════════╝")
        for i in range(self.ver):
            neighbors = ', '.join(map(str, sorted(self.adj[i])))
            lines.append(f"[{str(i).rjust(width)}] → {neighbors if neighbors else '∅'}")
        return '\n'.join(lines)
