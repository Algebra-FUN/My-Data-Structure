def find_all_st_path(adjlist, u, v, mp, ma):
    path = [u]
    solutions = set()

    def __find_all_path(w):
        for x in adjlist[w]:
            if x not in ma and x not in path:
                path.append(x)
                if x is v:
                    mp.issubset(path) and solutions.add((*path,))
                else:
                    __find_all_path(x)
                path.pop()
    __find_all_path(u)
    return solutions


if __name__ == "__main__":
    adjlist = [
        [1, 2, 3, 4],
        [0, 6, 8],
        [0],
        [0, 6],
        [0, 7],
        [8, 9],
        [1, 3, 7, 9],
        [4, 6, 10, 11],
        [1, 5, 12],
        [5, 6, 10, 12],
        [7, 9, 13],
        [7, 13],
        [8, 9, 14],
        [10, 11, 14],
        [12, 13]
    ]
    print(find_all_st_path(adjlist, 0, 14, {1, 5}, {3, 10}))
