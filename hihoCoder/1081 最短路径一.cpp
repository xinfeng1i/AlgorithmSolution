#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
using namespace std;

#if 1
int ChooseMinDist(vector<int>& dist, const deque<bool>& visited)
{
	int index = -1;
	int minDist = INT_MAX;
	for (size_t i = 0; i < dist.size(); ++i)
	{
		if (!visited[i] && dist[i] < minDist)
		{
			minDist = dist[i];
			index = i;
		}
	}
	return index;
}

vector<int> Dijkstra(int src, vector<vector<int>> graph)
{
	int N = graph.size();
	vector<int> dist(N, INT_MAX);
	deque<bool> visited(N, false);
	dist[src] = 0;

	for (int cnt = 0; cnt < N; ++cnt)
	{
		// choose the least dist unvisited node
		int u = ChooseMinDist(dist, visited);
		// visit the node
		visited[u] = true;
		// update its neighbors
		for (int v = 0; v < N; ++v)
		{
			if (graph[u][v] != 0)
			{
				if (dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];
				}
			}
		}
		
	}

	return dist;
}

void solve()
{
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	int u, v, w;
	vector<vector<int>> graph(N, vector<int>(N, 0));
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		if (graph[u-1][v-1] == 0)
		{
			graph[u-1][v-1] = w;
			graph[v-1][u-1] = w;
		}
		else if (w < graph[u-1][v-1])
		{
			graph[u-1][v-1] = w;
			graph[v-1][u-1] = w;
		}
	}

	vector<int> dist = Dijkstra(S-1, graph);
	int ans = dist[T-1];
	cout << ans << endl;
}

int main()
{
	freopen("data.in", "r", stdin);
	solve();
	return 0;
}
#endif //0