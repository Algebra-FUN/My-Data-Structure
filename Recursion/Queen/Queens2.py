def queens(n):
    solutions = []
    state = [None for _ in range(n)]

    def conflict(row, col):
        for j in range(col):
            if abs(state[j] - row) in (0, col-j):
                return True
        return False
        
    def put(col=0):
        for row in range(n):
            if not conflict(row, col):
                state[col] = row
                if col is n-1:
                    solutions.append(state.copy())
                else:
                    put(col+1)
    put(0)
    return solutions


for solution in queens(4):
    print(solution)
