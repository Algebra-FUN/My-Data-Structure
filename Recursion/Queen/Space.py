class AbsSpace:
    def __mul__(self,other):
        return Matmul(self,other)
    
    def __pow__(self,n):
        if not isinstance(n,int):
            raise Exception('parameter n must be interger')
        if n < 0:
            raise Exception('parameter n must be a positive interger')
        if n is 0:
            return 1
        if n is 1:
            return self
        other = Matmul(self,self)
        for i in range(n-2):
            other *= self
        return other

    def filter(self,condition):
        for item in self:
            if condition(item,self):
                yield item


class Matmul(AbsSpace):
    def __init__(self, mul1, mul2):
        self.mul1 = mul1
        self.mul2 = mul2

    def __iter__(self):
        for i1 in self.mul1:
            for i2 in self.mul2:
                yield i1+i2

class ZRange(AbsSpace):
    def __init__(self,start,end):
        self.line_range = range(start,end+1)

    def __iter__(self):
        for item in self.line_range:
            yield (item,)