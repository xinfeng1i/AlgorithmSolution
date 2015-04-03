#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <cstdio>
#include <climits>
using namespace std;

typedef long long llong;

// 选择当前未访问的最近的节点
int chooseMinDistNode(const vector<vector<llong>>& graph, const deque<bool>& visited, const vector<llong>& dist)
{
	int n = graph.size();

	int index = -1;
	llong minDist = LLONG_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && dist[i] < minDist)
		{
			index = i;
			minDist = dist[i];
		}
	}
	return index;
}

// 广度优先遍历的思想，每次选择尚未访问的最近节点访问
// 然后更新与之相邻的邻居的 dist 值
int Prim(const vector<vector<llong>>& graph, int src)
{
	int n = graph.size();

	deque<bool> visited(n, false);
	vector<llong> dist(n, LLONG_MAX);
	dist[src] = 0;

	llong ans = 0;
	for (int cnt = 0; cnt < n; ++cnt)
	{
		int u = chooseMinDistNode(graph, visited, dist);
		if (u == -1) break;
		visited[u] = true;
		ans += dist[u];
		for (int v = 0; v < n; ++v)
		{
			if (graph[u][v] != 0 && !visited[v])
			{
				if (graph[u][v] < dist[v])
				{
					dist[v] = graph[u][v];
				}
			}
		}
	}
	return ans;
}

int main()
{
	freopen("data.in", "r", stdin);
	int n;
	cin >> n;

	vector<vector<llong>> graph(n, vector<llong>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int ans = Prim(graph, 0);
	cout << ans << endl;
	return 0;
}