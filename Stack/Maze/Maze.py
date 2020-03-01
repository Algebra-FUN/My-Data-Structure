class Point:
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
    directions = [Point(*xy) for xy in [(-1, 0), (0, 1), (1, 0), (0, -1)]]
    wall = 1
    space = 0

    def __init__(self, maze):
        self.maze = maze

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
                if current == end:
                    return True
                for direction in Maze.directions:
                    point = current + direction
                    if self[point] is Maze.space and point not in route:
                        route.append(point)
                        del point, direction
                        if go():
                            return True
                        route.pop()
                return None
            go()
            return route


if __name__ == "__main__":
    maze = Maze([
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
    ])
    route = maze[(1, 1):(8, 8)]
    print(route)
