#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

#define INF 30000

vector<int> team;
vector<vector<int> > adjMatrix;
vector<int> dist;
vector<int> previous;
vector<bool> visited;
vector<bool> flag;
int ans = 0;
int maxTeam = 0;
int shortestPath = 0;

void dijkstra(int n, int c1)
{
    
    // Dijkstra Algorithm
    // Step 1: init dist array and the previous array
    dist.resize(n, INF);
    previous.resize(n, -1);
    dist[c1] = 0;
    previous[c1] = c1;

    // initial known world, empty, all nodes haven't been explore
    visited.resize(n, false);

    while (!all_of(visited.begin(), visited.end(), [](bool i){return i;}))
    {
        // pick the unknown node with the smallest dist[] value
        int min_dist = INF;
        int next_picked = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                next_picked = i;
            }
        }
        
        // add the picked node to the known region
        visited[next_picked] = true;

        for (int j = 0; j < n; ++j)
        {
            // update all the neighbor's dist
            // Relax progress
            if (adjMatrix[next_picked][j] != INF)
            {
                if (dist[j] > dist[next_picked] + adjMatrix[next_picked][j])
                {
                    dist[j] = dist[next_picked] + adjMatrix[next_picked][j];
                    previous[j] = next_picked;
                }
            }
        }

    }
}

void dfs(int n, int start, int end, int curLength, int curTeam)
{
    flag[start] = true;
    
    // has already reached the dist, judge whether the current
    // path is the shortest path
    if (start == end)
    {
        if (curLength == shortestPath)
        {
            // find shortest path, ans+1
            ans++;
            if (curTeam > maxTeam)
            {
                maxTeam = curTeam;
            }
        }

        return;
    }

    // not reached the end, but current path length is greater than
    // the shortest path length, there is no need to continue dfs, return
    if (curLength > shortestPath)
    {
        return;
    }

    // for neighbor, dfs recursively
    for (int j = 0; j < n; ++j)
    {
        if (!flag[j] && adjMatrix[start][j] != INF)
        {
            dfs(n, j, end, curLength + adjMatrix[start][j], curTeam + team[j]);

            // key point: reset the neighbor, who has finished the dfs, false
            // for other neighbors to reuse it to explore
            flag[j] = false;
        }
    }
    return;
}


int main()
{
    //freopen("1003data.txt", "r", stdin);    
    int n, m;
    int c1, c2;
    cin >> n >> m >> c1 >> c2;
    team.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> team[i];
    }

    adjMatrix.resize(n);
    for (int i = 0; i < n; ++i)
    {
        adjMatrix[i].resize(n, INF);
    }

    int s, e, weight;
    for (int i = 0; i < m; ++i)
    {
        cin >> s >> e >> weight;
        adjMatrix[s][e] = weight;   // undirected graph, symmetric matrix
        adjMatrix[e][s] = weight;
    }

    dijkstra(n, c1);
    shortestPath = dist[c2];
    
    flag.resize(n, false);
    dfs(n, c1, c2, 0, team[c1]);

    cout << ans << " " << maxTeam << endl;

#if 0
    // the shortest distance
    cout << "the shortest distance" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    cout << "the shortest path from c2 to c1" << endl;
    int tmp = c2;
    while (previous[tmp] != tmp)
    {
        cout << tmp << " ";
        tmp = previous[tmp];
    }
    cout << c1 << endl;
#endif

    return 0;
}
