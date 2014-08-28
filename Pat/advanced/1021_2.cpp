#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <climits>
#include <cstdio>
using namespace std;

void dfs(const vector<vector<int> >& graph, int src, deque<bool>& visited, vector<int>& level, int curLevel)
{
    visited[src] = true;
    level[src] = curLevel;
    for (int j = 0; j < graph[src].size(); ++j)
    {
        int v = graph[src][j];
        if (!visited[v])
        {
            dfs(graph, v, visited, level, curLevel + 1);
        }
    }
}

void bfs(const vector<vector<int> >&graph, int src, deque<bool>& visited, vector<int>& level, int curLevel)
{
    queue<int> q;
    visited[src] = true;
    level[src] = curLevel;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < graph[u].size(); ++j)
        {
            int v = graph[u][j];
            if (!visited[v])
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    vector<vector<int> > graph(n);
    int s = 0; int e = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d %d", &s, &e);
        graph[s-1].push_back(e-1);
        graph[e-1].push_back(s-1);
    }

    deque<bool> visited(n, false);
    vector<int> level(n, 0);
    int nComponents = 0;
    for (int u = 0; u < n; ++u)
    {
        if (!visited[u])
        {
            dfs(graph, u, visited, level, 1);
            nComponents++;
        }
    }

    if (nComponents >= 2)
    {
        printf("Error: %d components\n", nComponents);
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        level[i] = 0;
    }

    //dfs(graph, 0, visited, level, 1);
    bfs(graph, 0, visited, level, 1);
    int maxLevel = 0;
    int longestLeaf = -1;
    for (int i = 0; i < n; ++i)
    {
        if (level[i] > maxLevel)
        {
            maxLevel = level[i];
            longestLeaf = i;
        }
    }


    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        level[i] = 0;
    }

    //dfs(graph, longestLeaf, visited, level, 1);
    bfs(graph, longestLeaf, visited, level, 1);
    set<int> ans;
    maxLevel = 0;
    for (int i = 0; i < n; ++i)
    {
        if (level[i] > maxLevel)
        {
            maxLevel = level[i];
            ans.clear();
            ans.insert(i);
        }
        else if (level[i] == maxLevel)
        {
            ans.insert(i);
        }
    }
    ans.insert(longestLeaf);
    for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it + 1 << endl;
    }

    return 0;
}
