from BinaryTree import BinaryTree
from heapq import nsmallest
from matplotlib import pyplot as plt

def pop2min(queue):
    indexs = map(queue.index, nsmallest(2, queue))
    for index in indexs:
        yield queue.pop(index)


class HuffmanTree(BinaryTree):
    def __init__(self, *args, weight=0):
        super().__init__(*args)
        self.weight = weight  

    def __lt__(self, other):
        return self.weight < other.weight

    def __add__(self, other):
        return HuffmanTree(self.root+other.root, self, other, weight=self.weight+other.weight)

    def _node_repr(self):
        return f'{super()._node_repr()}<{round(self.weight,2)}>'

    @staticmethod
    def build(nodes):
        while len(nodes) > 1:
            min1, min2 = pop2min(nodes)
            nodes.append(min1+min2)
        return nodes[0]


class HuffmanCoder:
    def __init__(self, char_frequency): #
        nodes = [HuffmanTree(char, weight=frequency)
                 for char, frequency in char_frequency.items()]
        self.huffman_tree = HuffmanTree.build(nodes)
        self.code_dict = {}
        self.__code_dict(self.huffman_tree)

    def __code_dict(self, tree, code=''):
        if not any(tree.children()):
            self.code_dict[tree.root] = code
            return
        for i, child in enumerate(tree.children()):
            if child:
                self.__code_dict(child, code+str(i))

    def encode(self, txt):
        code = ''
        for char in txt:
            if char not in self.code_dict.keys():
                raise Exception(f'code<{char}> can\'t be encode')
            code += self.code_dict[char]
        return code

    def decode(self, code):
        tree = self.huffman_tree
        txt = ''
        for binary in str(code):
            tree = tree.children()[int(binary)]
            if not any(tree.children()):
                txt += tree.root
                tree = self.huffman_tree
        return txt


if __name__ == "__main__":
    char_frequency = {
        'a': 0.1,
        'b': 0.1,
        'c': 0.1,
        'd': 0.1,
        'e': 0.15,
        'f': 0.2,
        'g': 0.25
    }
    coder = HuffmanCoder(char_frequency)
    print(coder.huffman_tree)
    coder.huffman_tree.display_networkx_graph()
    plt.show()
    code = coder.encode('abcdefg')
    print(code)
    print(coder.decode(code))
