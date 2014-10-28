#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

//
// for person U, find a suitable job for him
//
bool DFS(const vector<vector<int> >& graph, int u, vector<int>& matchedR, deque<bool>& seen)
{
    // visited all his interested job
    for (int v = 0; v < graph[u].size(); ++v)
    {
        if (graph[u][v] != 0 && seen[v] == false)
        {
            seen[v] = true;
            // if this job has not been assigned to other person
            // or if this job has been assigned to other person, but that person can
            // find an alternative job
            if (matchedR[v] == -1 || DFS(graph, matchedR[v], matchedR, seen) == true)
            {
                matchedR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBipartiteMatch(const vector<vector<int> >& graph)
{
    int m = graph.size();
    int n = graph[0].size();

    vector<int> matchedR(n, -1);

    int ans = 0;

    // for each person, assign him a job recursively
    for (int u = 0; u < m; ++u)
    {
        deque<bool> seen(n, false);
        if (DFS(graph, u, matchedR, seen))
        {
            ans++;
        }
    }
    
    // print the match result
    for (int v = 0; v < matchedR.size(); ++v)
    {
        if (matchedR[v] != -1)
        {
            cout << matchedR[v] << "---" << v << endl;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int> > graph(6, vector<int>(6, 0));
    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[1][3] = 1;
    graph[2][2] = 1;
    graph[3][2] = 1; graph[3][3] = 1;
    graph[5][5] = 1;
    cout << "max bipartite matching is :" << maxBipartiteMatch(graph) << endl;
    return 0;
}
