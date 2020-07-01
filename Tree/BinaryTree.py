import networkx as nx
from matplotlib import pyplot as plt


class BinaryTree:
    def __init__(self, data=None, lchild=None, rchild=None):
        self.root = data
        self.lchild = lchild
        self.rchild = rchild

    @staticmethod
    def create(expression):
        if expression == '':
            return None
        if expression.count('(') != expression.count(')'):
            raise Exception('Expression invalid: Parentheses are not closed')
        if expression[0] == '(':
            raise Exception('Expression invalid: No node name')
        if '(' not in expression:
            return BinaryTree(expression)
        else:
            root = expression[0]
            children = expression[2:-1]
            txts = children.split(',')
            left = ''
            while txts:
                left += txts.pop(0)
                if left.count('(') is left.count(')'):
                    break
                left += ','
            right = ','.join(txts)
            return BinaryTree(root, BinaryTree.create(left), BinaryTree.create(right))

    def children(self):
        return self.lchild, self.rchild

    def _node_repr(self):
        return str(self.root) if self.root else '*'

    def __repr__(self):
        if any(self.children()):
            l, r = map(lambda x: x if x else '', self.children())
            return f'{self._node_repr()}({l},{r})'
        else:
            return self._node_repr()

    def __str__(self):
        return self.__repr__()

    def find(self, target):
        if self.root == target:
            return self
        for child in self.children():
            if child:
                result = child.find(target)
                if result:
                    return result
        return None

    def __len__(self):
        return 1 + sum(map(lambda x: len(x) if x else 0, self.children()))

    def height(self):
        return 1 + max(map(lambda x: x.height() if x else 0, self.children()))

    def __order_traversal(self, order):
        for target in order(self):
            if isinstance(target, BinaryTree):
                for _ in target.__order_traversal(order):
                    yield _
            elif target is not None:
                yield target

    def preorder_traversal(self):
        return self.__order_traversal(lambda x: (x.root, x.lchild, x.rchild))

    def inorder_traversal(self):
        return self.__order_traversal(lambda x: (x.lchild, x.root, x.rchild))

    def postorder_traversal(self):
        return self.__order_traversal(lambda x: (x.lchild, x.rchild, x.root))

    def __iter__(self):
        if self.lchild:
            for _ in self.lchild:
                yield _
        yield self
        if self.rchild:
            for _ in self.rchild:
                yield _

    def level_traversal(self):
        queue = [self]
        while queue:
            target = queue.pop(0)
            yield target.root
            for child in target.children():
                if child:
                    queue.append(child)

    def leaves(self):
        if not any(self.children()):
            yield self.root
        else:
            for child in self.children():
                if child:
                    for _ in child.leaves():
                        yield _

    def level_of_node(self, target):
        node = self.find(target)
        if node:
            return self.height() - node.height() + 1
        return None

    def lnodenum(self, target_level, current_level=1):
        if target_level is current_level:
            return 1
        return sum(map(lambda x: x.lnodenum(target_level, current_level+1) if x else 0, self.children()))

    @staticmethod
    def similar(u, v):
        if not any((u, v)):
            return True
        if None in (u, v):
            return False
        return all(map(lambda x, y: BinaryTree.similar(x, y), u.children(), v.children()))

    def __eq__(self, other):
        def attributes(x): return x.__dict__ if x else None
        return attributes(self) == attributes(other)

    def __ancestor(self, target, assembler):
        if any(map(lambda x: x and x.root == target, self.children())) or any(map(lambda x: x and x.__ancestor(target, assembler), self.children())):
            assembler.append(self.root)
            return True
        return False

    def ancestor(self, target):
        assembler = []
        self.__ancestor(target, assembler)
        return assembler

    def to_networkx_graph(self):
        graph = nx.Graph()
        graph.add_node(self._node_repr())
        self.__add_to_networkx_graph(graph)
        return graph

    def __add_to_networkx_graph(self, graph):
        for child in self.children():
            if child:
                graph.add_node(child._node_repr())
                graph.add_edge(self._node_repr(), child._node_repr())
                child.__add_to_networkx_graph(graph)

    def display_networkx_graph(self):
        graph = self.to_networkx_graph()
        nx.draw_kamada_kawai(graph, with_labels=True, font_weight='bold')


if __name__ == "__main__":
    # tree = BinaryTree.create('A(B(D(H(I,J(K,L)),G),S),C(E,F(M,)))')
    # # tree1 = BinaryTree.create('A(B(D(,F)),C(E,G))')
    # # tree2 = BinaryTree.create('A(B(D(,G)),C(E,))')
    # # tree3 = BinaryTree.create('A(B(D(,G)),C(E,))')
    # # print(BinaryTree.similar(tree,tree1))
    # # print(BinaryTree.similar(tree,tree2))
    # # print(tree==tree1)
    # # print(tree2==tree3)
    # print(tree)
    # tree.display_networkx_graph()
    # plt.show()
    bt = BinaryTree.create('a(b(,d),c(e,f))')
    print(*bt.preorder_traversal())
    print(*bt.inorder_traversal())
    print(*bt.postorder_traversal())
