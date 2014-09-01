#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int FindMinKey(const vector<int>& key, const deque<bool>& visited)
{
    int minkey = INT_MAX;
    int minindex = -1;
    int n = visited.size();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && key[i] < minkey)
        {
            minkey = key[i];
            minindex = i;
        }
    }
    return minindex;
}

void prim(const vector<vector<int> >& graph, int src, vector<int>& parent)
{
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    deque<bool> visited(n, false);

    key[src] = 0;
    for (int k = 0; k < n; ++k)
    {
        int u = FindMinKey(key, visited);
        if (u != -1)
        {
            visited[u] = true;
            for (int v = 0; v < n; ++v)
            {
                if (graph[u][v] > 0 && !visited[v] && graph[u][v] < key[v])
                {
                        key[v] = graph[u][v];
                        parent[v] = u;
                }
            }
        }
    }
    return;
}

void printSpanningTree(const vector<vector<int> >& graph, const vector<int>& parent)
{
    int n = parent.size();
    for (int v = 0; v < n; ++v)
    {
        int u = parent[v];
        if (u != -1)
        {
            cout << "Edge:" << u << "->" << v << ":" << graph[u][v] << endl;
        }
    }
    return;
}

int main()
{
    int n = 5;
    vector<vector<int> > graph(n, vector<int>(n, 0));
    graph[0][1] = 2; graph[0][3] = 6;
    graph[1][0] = 2; graph[1][2] = 3; graph[1][3] = 8; graph[1][4] = 5;
    graph[2][1] = 3; graph[2][4] = 7;
    graph[3][0] = 6; graph[3][1] = 8; graph[3][4] = 9;
    graph[4][1] = 5; graph[4][2] = 7; graph[4][3] = 9;

    vector<int> parent(n, -1);
    prim(graph, 0, parent);
    printSpanningTree(graph, parent);
    return 0;
}
