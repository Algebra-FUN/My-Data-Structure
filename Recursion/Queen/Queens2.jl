function queens(n)
    solutions = []
    state = [0 for _ ∈ 1:n]
    function conflict(row, col)
        for c ∈ 1:col - 1
            if abs(state[c] - row) ∈ (0, col - c)
                return true
            end
        end
        return false
    end
    function put(col=1)
        for row ∈ 1:n
            if !conflict(row,col)
                state[col] = row
                if col == n
                    solutions = [solutions;[copy(state)]]
                else
                    put(col+1)
                end
            end
        end
    end
    put()
    return solutions
end

for solution ∈ queens(4)
    println(solution)
end