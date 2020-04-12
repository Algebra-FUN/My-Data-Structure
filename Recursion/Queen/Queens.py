def queens(n):
    def next(state=()):
        next_col = len(state)

        def conflict(target_row):
            for col, row in enumerate(state):
                if abs(row-target_row) in (0, next_col-col):
                    return True
            return False

        for row in range(n):
            if not conflict(row):
                if next_col is n-1:
                    yield state+(row,)
                    return
                for result in next(state+(row,)):
                    yield result

    return next()


for solution in queens(8):
    print(solution)
