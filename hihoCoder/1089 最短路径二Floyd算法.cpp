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
const int INF = INT_MAX;
vector<vector<int>> Floyd(vector<vector<int>> graph)
{
	int N = graph.size();

	// init
	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] != 0) dist[i][j] = graph[i][j];
		}
	}

	// update
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

void solve()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(N, 0));
	int u, v, w;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		if (graph[u-1][v-1] == 0 || w < graph[u-1][v-1])
		{
			graph[u-1][v-1] = w;
			graph[v-1][u-1] = w;
		}
	}

	vector<vector<int>> dist = Floyd(graph);
	for (int i = 0; i < N; ++i) dist[i][i] = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j == 0) cout << dist[i][j];
			else cout << " " << dist[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	freopen("data.in", "r", stdin);
	solve();
	return 0;
}
#endif //0