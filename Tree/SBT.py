from BinaryTree import BinaryTree

class BST(BinaryTree):
    def __init__(self,*args,key=0):
        super().__init__(*args)
        self.key = key

    def insert(self,key,data):
        if self.key == key:
            return False
        if key < self.key:
            if self.lchild:
                self.lchild.insert(key,data)
            else:
                self.lchild = BST(data,key=key)
        elif key > self.key:
            if self.rchild:
                self.rchild.insert(key,data)
            else:
                self.rchild = BST(data,key=key)
        
    def __getitem__(self,key):
        if self.key == key:
            return self
        if key < self.key:
            if self.lchild:
                return self.lchild[key]
        elif key > self.key:
            if self.rchild:
                return self.rchild[key]
        return None

    def max(self):
        return max(self,key=lambda x: x.key)    

    @staticmethod
    def create(*args):
        if not args:
            return None
        args = [*args]
        key,data = args.pop(0)
        bst = BST(data,key=key)
        for key,data in args:
            bst.insert(key,data)
        return bst

if __name__ == "__main__":
    arr = (5,2,1,6,7,4,8,3,9)
    bst = BST.create(*zip(arr,arr))
    print(bst)