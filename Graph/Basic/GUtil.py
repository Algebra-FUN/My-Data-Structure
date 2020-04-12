from Graph import *

def exist_path(G: Graph, u_loc: int or str, v_loc: int or str) -> bool:
    v_id = G[v_loc].id
    for node in G.DFS(u_loc):
        if node.id is v_id:
            return True
    return False

if __name__ == "__main__":
    from GFamily import NodLinGraph
    G = NodLinGraph(
        names='ABCDEF',
        edges_by_names=(
            ('A', 'B'),
            ('A', 'C'),
            ('C', 'B'),
            ('A', 'D'),
            ('C', 'E'),
            ('D', 'F')
        )
    )
    print(exist_path(G,'C','F'))