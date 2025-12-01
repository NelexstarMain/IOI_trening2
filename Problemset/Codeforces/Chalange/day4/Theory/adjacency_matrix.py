class Grafs:
    def __init__(self, vertexes) -> None:
        self.adj: list[list[int]] = [[0 for _ in range(vertexes)] for _ in range(vertexes)]
        self.ver = vertexes

    def add_edge(self, a, b) -> None:
        self.adj[a][b] = 1

    def draw_graph(self) -> str:
        lines = []
        width = len(str(self.ver - 1))
        lines.append("╔══════════════════════╗")
        lines.append("║   Lista sąsiedztwa   ║")
        lines.append("╚══════════════════════╝")
        for i in range(len(self.adj)):
            neighbors = ', '.join(str(x) for x in range(len(self.adj[i])) if self.adj[i][x] == 1)
            lines.append(f"[{str(i).rjust(width)}] → {neighbors if neighbors else '∅'}")
        return '\n'.join(lines)

