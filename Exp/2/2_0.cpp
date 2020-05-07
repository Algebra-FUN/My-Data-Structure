#include <iostream>
#include <list>
#define N 15
#define nil -1

using namespace std;

struct Node
{
    int adjvex;
    Node *nextarc;
};

struct AdjGraph
{
    Node adjlist[N];
};

Node *parseToNodeList(int list[N])
{
    Node *p = nullptr;
    for (int j = 0; list[j] != nil; ++j)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->adjvex = list[j];
        node->nextarc = p;
        p = node;
    }
    return p;
}

AdjGraph *parseToAdjGraph(int table[N][N])
{
    AdjGraph *G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (int i = 0; i < N; ++i)
        G->adjlist[i] = *parseToNodeList(table[i]);
    return G;
}

int path[N];
int path_p = 0;
bool visited[N];

void printPath()
{
    for (int i = 0; path[i] != nil; ++i)
        cout << path[i] << ' ';
    cout << endl;
}

bool pass_all(int mp[N])
{
    for (int i = 0; mp[i] != nil; ++i)
        if (!visited[mp[i]])
            return false;
    return true;
}

void _find_all_st_path(AdjGraph *G, int u, int v, int mp[N])
{
    if (u == v)
    {
        if(pass_all(mp))
            printPath();
        return;
    }
    Node *p = &G->adjlist[u];
    while (p != nullptr)
    {
        int w = p->adjvex;
        if (!visited[w])
        {
            ++path_p;
            visited[w] = true;
            path[path_p] = w;
            _find_all_st_path(G, w, v, mp);
            path[path_p] = nil;
            visited[w] = false;
            --path_p;
        }
        p = p->nextarc;
    }
}

void find_all_st_path(AdjGraph *G, int u, int v, int mp[N], int ma[N])
{
    for (int i = 0; i < N; ++i)
        visited[i] = false, path[i] = nil;
    for (int i = 0; ma[i] != nil; ++i)
        visited[ma[i]] = true;
    visited[0] = true, path[0] = u, path_p = 0;
    _find_all_st_path(G, u, v, mp);
}

int main()
{
    int adjlist[N][N] = {
        {1, 2, 3, 4, nil},
        {0, 6, 8, nil},
        {0, nil},
        {0, 6, nil},
        {0, 7, nil},
        {8, 9, nil},
        {1, 3, 7, 9, nil},
        {4, 6, 10, 11, nil},
        {1, 5, 12, nil},
        {5, 6, 10, 12, nil},
        {7, 9, 13, nil},
        {7, 13, nil},
        {8, 9, 14, nil},
        {10, 11, 14, nil},
        {12, 13, nil}};
    AdjGraph *G = parseToAdjGraph(adjlist);
    int mp[N] = {1, 5, nil}, ma[N] = {3, 10, nil};
    find_all_st_path(G, 0, 14, mp, ma);
}
