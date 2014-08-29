#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool canFindMatch(const vector<vector<int> >& graph, int u, deque<bool>& visited, vector<int>& matchR)
{
    for (int v = 0; v < graph[u].size(); ++v)
    {
        if (graph[u][v] > 0 && !visited[v])
        {
            visited[v] = true;
            if (matchR[v] == -1 || canFindMatch(graph, matchR[v], visited, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bpm(const vector<vector<int> >& graph)
{
    int cnt = 0;
    int m = graph.size();
    int n = graph[0].size();
    vector<int> matchR(n, -1);
    for (int u = 0; u < m; ++u)
    {
        deque<bool> visited(n, false);
        if (canFindMatch(graph, u, visited, matchR))
        {
            cnt++;
        }
    }

    // print the maximum match
    for (int v = 0; v < n; ++v)
    {
        int u = matchR[v];
        if (u != -1)
        {
            cout << "Left" << u << "->" << "right" << v << endl;
        }
    }

    return cnt;
}

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int> > graph(m, vector<int>(n, 0));
    graph[0][1] = 2;
    graph[1][0] = 3; graph[1][2] = 1;
    graph[2][0] = 2; graph[2][1] = 4;

    int ans = bpm(graph);
    cout << "the maximum matching is:" << ans << endl;
    return 0;
}
