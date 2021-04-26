class Point:
    '''A custom type which supports Maze'''

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x is other.x and self.y is other.y

    def __add__(self, other):
        return Point(self.x+other.x, self.y+other.y)

    def __repr__(self):
        return '({},{})'.format(self.x, self.y)

    def __iter__(self):
        yield self.x
        yield self.y


class Maze:
    '''The Maze is a type which support find path when give the start and end point'''
    directions = [Point(*xy) for xy in [(-1, 0), (0, 1), (1, 0), (0, -1)]]
    wall = 1
    space = 0

    def __init__(self, maze, painter=None):
        self.maze = maze
        self.painter = painter

    def __getitem__(self, indices):
        if isinstance(indices, Point):
            x, y = indices
            return self.maze[x][y]
        if isinstance(indices, slice):
            start, end = map(lambda x: Point(
                *x), (indices.start, indices.stop))
            route = [start]

            def go():
                current = route[-1]
                if current == end:  # arrive the end
                    return True
                for direction in Maze.directions:   # travese and try 4 direction
                    point = current + direction    # get the next point in direction
                    # check the next point is ok(1.not wall & 2.not repeated)
                    if self[point] is Maze.space and point not in route:
                        # push the point into route stack
                        route.append(point)
                        del point, direction
                        self.painter(route)
                        if go():                # the route is not impasse
                            return True
                        route.pop()
                        # this route is impasse and pop point
                        self.painter(route)
                return None     # try the all direction and confirm this route is impasse
            go()
            return route


if __name__ == "__main__":
    from matplotlib import pyplot as plt
    maze_map = [
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
        [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    ]
    i = 0
    def painter(route):
        global i
        plt.cla()
        map_ = [row.copy() for row in maze_map]
        for point in route:
            x, y = point
            map_[x][y] = -1
        plt.imshow(map_)
        plt.pause(.5)
        plt.savefig(f'./temp/{i}.png')
        i += 1
    maze = Maze(maze_map, painter)
    plt.ion()
    plt.show()
    route = maze[(1, 1):(8, 8)]
    plt.ioff()
    print(route)
