#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 
 * Bellman Ford algorithm
 * Find all the shortest path from a single source
 * the edge weight can be negative
 */

/*
 * Basic Step
 * Step 1: dist[s] = 0; dist[u] = INF
 * Step 2: repeated |V| - 1 times
 *         for each edge u->v
 *         if dist[u] + uv < dist[v]
 *         update dist[v] = dist[u] + uv
 * step 3: do step 2 one more time
 *         if any dist change, report negative circle
 *         else return
 */

const int INF = 99999;
vector<int> BellmanFord(vector<vector<int> > graph, int src)
{
	int n = graph.size();
	
	// step 1: init
	vector<int> dist(n, INF);
	dist[src] = 0;

	// step 2: repeat |V| - 1 times
	for (int times = 0; times < n - 1; ++times)
	{
		// for each edge u->v
		for (int u = 0; u < n; ++u)
		{
			for (int v = 0; v < n; ++v)
			{
				if (graph[u][v] != INF && dist[u] != INF &&
					dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];
				}
			}
		}
	}

	// Step 3: do one more time
	for (int u = 0; u < n; ++u)
	{
		for (int v = 0; v < n; ++v)
		{
			if (graph[u][v] != INF && dist[u] != INF &&
					dist[u] + graph[u][v] < dist[v])
			{
				//dist[v] = dist[u] + graph[u][v];
				cerr << "The Graph has negative Circle" << endl;
			}
		}
	}

	return dist;
}

int main()
{
	vector<vector<int> > graph(5, vector<int>(5, INF));
	graph[0][1] = -1; graph[0][2] = 4;
	graph[1][2] = 3;  graph[1][3] = 2; graph[1][4] = 2;
	graph[3][2] = 5;  graph[3][1] = 1;
	graph[4][3] = -3;

	vector<int> dist = BellmanFord(graph, 0);

	cout << "The shortest path form node 0 to others is : " << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << 0 << " " << i << " " << dist[i] << endl;
	}
	cout << endl;

	return 0;
}
