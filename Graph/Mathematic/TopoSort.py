def TopoSort(adjlist):
    indegs = [0 for _ in adjlist]
    for adjvexs in adjlist:
        for v in adjvexs:
            indegs[v] += 1
    stack = []
    for u,indeg in enumerate(indegs):
        if indeg is 0:
            stack.append(u)
    while stack:
        u = stack.pop()
        yield u
        for v in adjlist[u]:
            indegs[v] -= 1
            if indegs[v] is 0:
                stack.append(v)

if __name__ == "__main__":
    adjlist = [
        [2],
        [3,4,6],
        [3],
        [4,5],
        [],
        [],
        [5]
    ]
    print(*TopoSort(adjlist))
