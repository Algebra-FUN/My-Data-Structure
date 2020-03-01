#include <iostream>
#include <vector>

using namespace std;

const int M = 8, N = 8;

int maze[M + 2][N + 2] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

};

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point *add(Point *other)
    {
        Point *point = new Point(0, 0);
        point->x = this->x + other->x;
        point->y = this->y + other->y;
        return point;
    }
    bool eq(Point *other){
        return this->x == other->x && this->y == other->y;
    }
    bool in(vector<Point *> ps){
        for(int i = 0;i < ps.size();i++){
            Point *point = ps[i];
            if(this->eq(point))
                return true;
        }
        return false;
    }
    bool notIn(vector<Point *> ps){
        return !this->in(ps);
    }
    void println(){
        cout << '(' << this->x << ',' << this->y << ')' << endl;
    }
};

Point *start = new Point(1, 1);
Point *stop = new Point(8, 8);
Point *directions[] = {
    new Point(-1, 0),
    new Point(0, 1),
    new Point(1, 0),
    new Point(0, -1),
};
vector<Point *> route;

bool go()
{
    Point *current = route[route.size()-1];
    if(current->eq(stop))
        return true;
    for(int i = 0;i < 4;i++){
        Point *direction = directions[i];
        Point *point = current->add(direction);
        int x = point->x,y = point->y;
        if(maze[x][y] == 0 && point->notIn(route)){
            route.push_back(point);
            if(go())
                return true;
            route.pop_back();
        }
    }
    return false;
}

bool findRoute()
{
    route.clear();
    route.push_back(start);
    return go();
}

int main()
{
    cout << "can find the route of the maze: " << findRoute() << endl;
    for(int i = 0;i < route.size();i++)
        route[i]->println();
}