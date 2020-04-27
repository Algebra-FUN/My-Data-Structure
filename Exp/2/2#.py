def find_all_st_path(adjlist,u,v,mp,ma):
    """
    算法功能：无向图找出所有满足条件的Path
    参数：
    * adjlist:邻接表
    * u:起点
    * v:终点
    * mp:必经点集合
    * ma:必避点集合
    返回:解集合
    """
    # 初始化路径
    path = [u]
    # 初解集合，用于存放满足条件的路径
    solutions = set()
    # 函数找w->v的路径，w：当前途径点
    def __find_all_path(w):
        # 对于所有w的邻接点x 
        for x in adjlist[w]:
            # 若 x不是必避点 且 x不重复
            if x not in ma and x not in path:
                # 向path中添加x
                path.append(x)
                # 若 达到终点(w是v)
                if x is v:
                    # 若 经过所有必经点(必经点集是路径点集的子集)
                    mp.issubset(path) and solutions.add((*path,))
                # 否则 递归找x->v的路径
                else:
                    __find_all_path(x)
                # 从path中移除x
                path.pop()
    __find_all_path(u)
    return solutions

def remove_must_avoids(adjlist,ma):
   return [[*{*adj_vs} - ma] for adj_vs in adjlist]

    
if __name__ == "__main__":
    adjlist = [
        [1,2,3,4],
        [0,6,8],
        [0],
        [0,6],
        [0,7],
        [8,9],
        [1,3,7,9],
        [4,6,10,11],
        [1,5,12],
        [5,6,10,12],
        [7,9,13],
        [7,13],
        [8,9,14],
        [10,11,14],
        [12,13]  
    ]
    print(find_all_st_path(adjlist,0,14,{1,5},{3,10}))
    # print(remove_must_avoids(adjlist,{3,10}))