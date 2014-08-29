#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool bfs(const vector<vector<int> >& graph, int s, int t, deque<bool>& visited, vector<int>& parent)
{
    queue<int> q;

    visited[s] = true;
    parent[s] = -1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < graph[u].size(); ++v)
        {
            if (graph[u][v] > 0 && !visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return visited[t] == true;
}

void printPath(const vector<int>& parent, int u)
{
    if (parent[u] == -1) 
    {
        cout << " " << u;
    }
    else 
    {
        printPath(parent, parent[u]);
        cout << " " << u;
    }
}

int maxFlow(const vector<vector<int> >& graph, int s, int t)
{
    int maxflow = 0;

    // residual graph
    int n = graph.size();
    vector<vector<int> > rGraph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            rGraph[i][j] = graph[i][j];
        }
    }

    // while there is a argument path in the residual graph, find it
    while (true)
    {
        deque<bool> visited(n, false);
        vector<int> parent(n, -1);
        // find argument path
        bool flag = bfs(rGraph, s, t, visited, parent);        
        if (!flag) break;

        // compute the minimum capacity of the argument path
        int pathFlow = INT_MAX;
        for (int v = t; parent[v] != -1; v = parent[v])
        {
            int u = parent[v];
            if (rGraph[u][v] < pathFlow)
            {
                pathFlow = rGraph[u][v];
            }
        }

        // update the residual Graph
        for (int v = t; parent[v] != -1; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        // update the maxflow
        maxflow += pathFlow;

        // print the path
        cout << "path:";
        printPath(parent, t);
        cout << endl;
    }

    return maxflow;
}

int main()
{
    int n = 8;
    vector<vector<int> > graph(n, vector<int>(n, 0));
    graph[0][1] = 1; graph[0][2] = 1; graph[0][3] = 1;
    graph[1][2] = 1;
    graph[2][6] = 1; graph[2][3] = 1;
    graph[3][6] = 1;
    graph[4][2] = 1; graph[4][7] = 1;
    graph[5][1] = 1; graph[5][4] = 1; graph[5][7] = 1;
    graph[6][5] = 1; graph[6][7] = 1;

    int ans = maxFlow(graph, 0, 7);
    cout << "max flow: " << ans << endl;
    return 0;
}
