class Node:
    def __init__(self, id, name=None, data=None):
        self.id = id
        self.name = name if name else f'*{id}'
        self.data = data
        self.edges = []
        self.weights = []
    
    def __repr__(self):
        return f'{self.name}<{self.id}>'

    def __str__(self):
        return self.__repr__()

    def add_edge(self, node, weight=1):
        self.edges.append(node)
        self.weights.append(weight)
