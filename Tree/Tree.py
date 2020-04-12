class Tree:
    def __init__(self, tag='*', children=()):
        self.tag = tag
        self.children = children

    def __repr__(self):
        return self.tag + (str(self.children) if any(self.children) else '')

    def __str__(self):
        return self.__repr__()

    def __iter__(self):
        for child in self.children:
            yield child

    def __meature(self, fun):
        def meature(target):
            if any(target.children):
                return 1 + fun([meature(child) for child in target.children])
            return 1
        return meature(self)

    def __len__(self):
        return self.__meature(sum)

    def height(self):
        return self.__meature(max)

