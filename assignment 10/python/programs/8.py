from collections import defaultdict


class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)  # For an undirected graph

    def print_adjacency_list(self):
        for node in self.graph:
            neighbors = self.graph[node]
            neighbor_str = " -> ".join(map(str, neighbors))
            print(f"{node} -> {neighbor_str}")


# Example usage:
if __name__ == "__main__":
    g = Graph()
    g.add_edge(1, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 3)
    g.add_edge(2, 4)
    g.add_edge(3, 4)
    g.add_edge(4, 5)

    print("Adjacency List:")
    g.print_adjacency_list()
