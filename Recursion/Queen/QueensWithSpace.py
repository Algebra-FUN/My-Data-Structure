from Space import ZRange


def queens(n):
    queens_space = ZRange(1, n)**n

    def check(item, self):
        for col in range(n):
            for j in range(col):
                if abs(item[col]-item[j]) in (0, col-j):
                    return False
        return True
    return queens_space.filter(check)


for _ in queens(4):
    print(_)
