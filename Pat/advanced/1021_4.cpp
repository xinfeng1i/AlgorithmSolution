#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <cstdio>
#include <cstdlib>
using namespace std;
/* 算法思想：
 * 1. 首先采用并查集来判断连通性，并且给出连通分支的数量
 * 2. 然后任取一个点x做bfs遍历，找到所有距离x最远的节点集y1, y2, y3...
 * 3. 再从集合y中任意选择一个节点y1进行第二次bfs遍历，得到距离y1最远的节点集
 *    合z1,z2,z3...，则所有在y集合和z集合中的点{y1,y2,y3...,z1,z2,z3...}
 *    即为所求的deepest root
 */

vector<int> parent;
vector<int> myrank;
void MakeSet(int x)
{
    parent[x] = x;
    myrank[x] = 0;
}

int Find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int rootx, int rooty)
{
    if (myrank[rootx] < myrank[rooty])
    {
        parent[rootx] = rooty;
    }
    else
    {
        parent[rooty] = rootx;
        if (myrank[rootx] == myrank[rooty])
        {
            myrank[rootx] += 1;
        }
    }
}

int bfs(const vector<vector<int> >& adjList, int src, deque<bool>& visited, vector<int>& level)
{
    int maxLevel = -1;
    queue<int> q;
    visited[src] = true;
    level[src] = 0;
    maxLevel = max(maxLevel, level[src]);
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < adjList[u].size(); ++j)
        {
            int v = adjList[u][j];
            if (!visited[v])
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                maxLevel = max(maxLevel, level[v]);
                q.push(v);
            }
        }
    }

    return maxLevel;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    myrank.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; ++i)
    {
        myrank[i] = 0;
        parent[i] = i;
    }

    vector<vector<int> > adjList(n);
    int s = 0; int e = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        scanf("%d %d", &s, &e);
        adjList[s-1].push_back(e-1);
        adjList[e-1].push_back(s-1);

        int rootx = Find(s-1);
        int rooty = Find(e-1);
        if (rootx != rooty) Union(rootx, rooty);
    }

    set<int> parents;
    for (int i = 0; i < n; ++i)
    {
        parents.insert(parent[i]);
    }
    int nComponents = parents.size();
    if (nComponents >= 2)
    {
        printf("Error: %d components\n", nComponents);
        return 0;
    }

    set<int> ans;

    // first dfs
    deque<bool> visited(n, false);
    vector<int> level(n, -1);
    int maxLevel = bfs(adjList, 0, visited, level);
    for (int i = 0; i < n; ++i)
    {
        if (level[i] == maxLevel)
        {
            ans.insert(i);
        }
    }

    // second bfs
    visited.resize(n);
    level.resize(n);
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
        level[i] = -1;
    }
    maxLevel = bfs(adjList, *(ans.begin()), visited, level);
    for (int i = 0; i < n; ++i)
    {
        if (level[i] == maxLevel)
        {
            ans.insert(i);
        }
    }

    for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it + 1 << endl;
    }
    return 0;
}
