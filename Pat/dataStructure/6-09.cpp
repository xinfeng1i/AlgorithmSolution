#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 100000;
const int N = 10000 + 5;
bool visited[N];

void dfs(const vector<vector<int> >& graph, int start)
{
	int n = graph.size();
	visited[start] = true;
	for (int j = 0; j < n; ++j)
	{
		if (j != start && graph[start][j] != INF && !visited[j])
		{
			dfs(graph, j); 
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);

	// init
	vector<vector<int> > dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i) dist[i][i] = 0;
	for (int i = 0; i < N; ++i) visited[i] = false;

	// input
	int src, dest;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &src, &dest);
		dist[src-1][dest-1] = 1;
		dist[dest-1][src-1] = 1;
	}

	// whether the graph is connected ?
	bool isConnected = true;
	dfs(dist, 0);
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i]) isConnected = false;	
	}


	int k = 0;
	scanf("%d", &k);
	vector<int> query(k, 0);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &query[i]);
	}

	// floyd-warshall algorithm
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][k] != INF && 
					dist[k][j] != INF && 
					dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	if (isConnected)
	{
		// compute CC and output
		for (int i = 0; i < k; ++i)
		{
			int node = query[i] - 1;
			int tmpsum = 0;
			for (int j = 0; j < n; ++j)
			{
				if (j != node && dist[node][j] != INF)
				{
					tmpsum += dist[node][j];
				}
			}

			double cc = (double)(n - 1) / tmpsum;
			printf("Cc(%d)=%.2f\n", node + 1, cc);
		}
	}
	else
	{
		for (int i = 0; i < k; ++i)
		{
			int node = query[i] - 1;
			printf("Cc(%d)=0.00\n", node + 1);
		}
	}

	return 0;
}
