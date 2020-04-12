from Graph import Graph


class NodLinGraph(Graph):
    '''NodeLineGraph'''
    def __init__(self, names, edges_by_names):
        super().__init__()
        for name in names:
            self.add_node(name)
        for edge in edges_by_names:
            self.add_edge_by_name(*edge)


if __name__ == "__main__":
    from matplotlib import pyplot as plt
    G = NodLinGraph(
        names='ABCDEF',
        edges_by_names=(
            ('A', 'B'),
            ('A', 'C'),
            ('C', 'B'),
            ('A', 'D'),
            ('C', 'E'),
            ('D', 'F')
        )
    )
    print(list(G.DFS('C')))
    print(list(G.BFS('C')))
    G.display_graph_by_networkx()
    plt.show()
