#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
    int cost;
    bool operator<(const Edge& other) const
    {
        if (start < other.start)
        {
            return true;
        }
        else if (start == other.start)
        {
            if (weight < other.weight)
            {
                return true;
            }
            else if (weight > other.weight)
            {
                return false;
            }
            else
            {
                return cost < other.cost;
            }
        }
        else
        {
            return false;
        }
    }
};

bool isAllVisited(vector<bool> flag)
{
    for (int i = 0; i < flag.size(); ++i)
    {
        if (!flag[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    //freopen("1030data.txt", "r", stdin);
    int N = 0;
    long M = 0;
    int S = 0; 
    int D = 0;
    cin >> N >> M >> S >> D;

    vector<int> dist(N, 10000);
    vector<long> distcost(N, 300000);
    vector<bool> isVisited(N, false);
    vector<int> prev(N, -1);
    vector<Edge> edges(M);
    for (long i = 0; i < M; ++i)
    {
        cin >> edges[i].start >> edges[i].end
            >> edges[i].weight >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    // Dijkstra Algorithm to calculate shortest path
    // Shortest path from S to all the other nodes
    dist[S] = 0;
    distcost[S] = 0;

    // not all nodes have been added into R, loop
    while (!isAllVisited(isVisited))
    {
        // choose node u such that dist[u] smallest
        int u = -1;
        int min_u = 10000;
        long cost_u = 300000;
        for (int i = 0; i < N; ++i)
        {
            if (!isVisited[i] && dist[i] < min_u)
            {
                u = i;
                min_u = dist[i];
                cost_u = distcost[i];
            }
            else if (!isVisited[i] && dist[i] == min_u && distcost[i] < cost_u)
            {
                u = i;
                min_u = dist[i];
                cost_u = distcost[i];
            }
        }

        // add u
        isVisited[u] = true;

        // update all the dist[v] which (u,v) in E
        for (long i = 0; i < M; ++i)
        {
            if (edges[i].start == u)
            {
                int v = edges[i].end;
                int weight = edges[i].weight;
                int costt = edges[i].cost;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    distcost[v] = distcost[u] + costt;
                }
                else if (dist[v] == dist[u] + weight && 
                         distcost[v] < distcost[u] + costt)
                {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    distcost[v] = distcost[u] + costt;

                }
            }
        }
    }

    cout << "path backwards:" << endl;
    cout << D << " ";
    while (prev[D] != -1)
    {
        cout << prev[D] << " ";
        D = prev[D];
    }
    cout << endl;
    
    return 0;
}
