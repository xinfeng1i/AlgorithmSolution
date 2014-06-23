#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 10000;
typedef vector<vector<int> > Matrix;

// time complexity: O(n)
int minDistance(const vector<int>& visited, const vector<int>& dist)
{
    int n = dist.size();
    int minDist = INF; int min_index = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void DijkstraAlgorithm(int src,  const Matrix& graph)
{
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> dist(n, INF);
    dist[src] = 0;
    vector<int> parent(n, -1);

    for (int cnt = 0; cnt < n; ++cnt)
    {
        int u = minDistance(visited, dist);
        visited[u] = 1;  // visit current node
        for (int v = 0; v < n; ++v)
        {
            // update neighbor
            if (graph[u][v] != 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // print
    cout << "the shortest path length is:" << endl;
    for (int i = 0; i < n; ++i)
    {
        if (i != src)
        {
            cout << src << "-" << i << " : " << dist[i] << endl;
            cout << "  path is:";
            int x = i;
            while (x != -1)
            {
                cout << " " << x;
                x = parent[x];
            }
            cout << endl;
        }
    }
    cout << endl;

    return;
}
/* Time complexity of this implementation is: O(n^2).
 * find the minimum dist complexity is: O(n).
 */

int main()
{
    vector<vector<int> > g(9, vector<int>(9, 0));
    g[0][1] = 4; g[0][7] = 8;
    g[1][0] = 4; g[1][2] = 8; g[1][7] = 11;
    g[2][1] = 8; g[2][3] = 7; g[2][5] = 4; g[2][8] = 2;
    g[3][2] = 7; g[3][4] = 9; g[3][5] = 14; 
    g[4][3] = 9; g[4][5] = 10;
    g[5][2] = 4; g[5][4] = 10; g[5][6] = 2;
    g[6][3] = 14; g[6][5] = 2; g[6][7] = 1; g[6][8] = 6;
    g[7][0] = 8; g[7][1] = 11; g[7][6] = 1; g[7][8] = 7;
    g[8][2] = 2; g[8][6] = 6; g[8][7] = 7;

    cout << "The Graph is: " << endl;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << " " << g[i][j];
        }
        cout << endl;
    }
    cout << endl;


    DijkstraAlgorithm(0, g);
    return 0;
}
