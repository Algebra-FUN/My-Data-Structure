function queens(n)
    solutions = []
    function put!next(state = [])
        next_col = length(state) + 1
        if next_col > n
            solutions = [solutions;[state]]
            return
        end
        function conflict(target_row)
            for (col, row) ∈ enumerate(state)
                if abs(row - target_row) ∈ (0, next_col - col)
                    return true
                end
            end
            return false
        end
        for row ∈ 1:n
            conflict(row) || put!next([state;[row]])
        end
    end
    put!next()
    return solutions
end

for q ∈ queens(4)
    println(q)
end