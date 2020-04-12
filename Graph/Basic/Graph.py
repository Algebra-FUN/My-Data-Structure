from GNode import Node
import networkx as nx


class Graph:
    def __init__(self):
        self.node_names = []
        self.node_list = []

    def __len__(self):
        return len(self.node_list)

    def __getitem__(self, target):
        if isinstance(target, slice) or isinstance(target, int):
            return self.node_list[target]
        if isinstance(target, str):
            index = self.node_names.index(target)
            return self[index]

    def __iter__(self):
        return iter(self.node_list)

    def add_node(self, name, data=None):
        node = Node(len(self), name, data)
        self.node_list.append(node)
        self.node_names.append(name if name else node.index)
        return node

    def add_edge_by_index(self, start_index, end_index, weight=1):
        start_node = self[start_index]
        start_node.add_edge(self[end_index])

    def add_edge_by_name(self, start_name, end_name, weight=1):
        self.add_edge_by_index(self[start_name].id, self[end_name].id, weight)

    def to_networkx_graph(self):
        G = nx.Graph()
        for node_name in self.node_names:
            G.add_node(node_name)
        for u in self:
            for v in u.edges:
                G.add_edge(u.name, v.name)
        return G

    def DFS(self, start):
        visited = [False for _ in self]

        def _DFS_(id):
            visited[id] = True
            u = self[id]
            yield u
            for v in u.edges:
                if not visited[v.id]:
                    for _ in _DFS_(v.id):
                        yield _
        return _DFS_(start if isinstance(start, int) else self[start].id)

    def BFS(self, start):
        visited = [False for _ in self]
        queue = [self[start]]
        while queue:
            u = queue.pop(0)
            visited[u.id] = True
            yield u
            for v in u.edges:
                if not visited[v.id]:
                    queue.append(v)

    def display_graph_by_networkx(self):
        graph = self.to_networkx_graph()
        nx.draw_kamada_kawai(graph, with_labels=True, font_weight='bold')
