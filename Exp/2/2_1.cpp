#include <iostream>
#define N 15
#define end -1

using namespace std;

int path[N];
int path_p = 0;
bool visited[N];

bool print_path()
{
    for (int i = 0; path[i] != end; ++i)
        cout << path[i] << ' ';
    cout << endl;
    return true;
}

bool pass_all(int mp[N])
{
    for (int i = 0; mp[i] != end; ++i)
        if (!visited[mp[i]])
            return false;
    return true;
}

void _find_all_st_path(int adjlist[N][N], int u, int v, int mp[N])
{
    int *adjvex = adjlist[u], w;
    for (int i = 0; adjvex[i] != end; ++i)
    {
        w = adjvex[i];
        if (!visited[w])
        {
            ++path_p, visited[w] = true, path[path_p] = w;
            if (w == v)
                pass_all(mp) && print_path();
            else
                _find_all_st_path(adjlist, w, v, mp);
            path[path_p] = end, visited[w] = false, --path_p;
        }
    }
}

void find_all_st_path(int adjlist[N][N], int u, int v, int mp[N], int ma[N])
{
    for (int i = 0; i < N; ++i)
        visited[i] = false, path[i] = end;
    for (int i = 0; ma[i] != end; ++i)
        visited[ma[i]] = true;
    visited[0] = true, path[0] = u, path_p = 0;
    _find_all_st_path(adjlist, u, v, mp);
}

int main()
{
    int adjlist[N][N] = {
        {1, 2, 3, 4, end},
        {0, 6, 8, end},
        {0, end},
        {0, 6, end},
        {0, 7, end},
        {8, 9, end},
        {1, 3, 7, 9, end},
        {4, 6, 10, 11, end},
        {1, 5, 12, end},
        {5, 6, 10, 12, end},
        {7, 9, 13, end},
        {7, 13, end},
        {8, 9, 14, end},
        {10, 11, 14, end},
        {12, 13, end}};
    int mp[N] = {1, 5, end}, ma[N] = {3, 10, end};
    find_all_st_path(adjlist, 0, 14, mp, ma);
}
