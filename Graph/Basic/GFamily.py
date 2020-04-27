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
        names='012345',
        edges_by_names=(
            ('0', '1'),
            ('1', '2'),
            ('2', '3'),
            ('4', '1'),
            ('4', '5'),
            ('5', '3')
        )
    )
    print(*G.topo_sort())
    G.display_graph_by_networkx()
    plt.show()
