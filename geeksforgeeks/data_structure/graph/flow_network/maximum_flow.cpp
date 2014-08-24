#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

bool bfs(const vector<vector<int> >& matrix, deque<bool>& visited, vector<int>& parent, int src, int dest)
{
	queue<int> q;
	visited[src] = true;
	parent[src] = -1;
	q.push(src);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < matrix[u].size(); ++v)
		{
			if (!visited[v] && matrix[u][v] != 0)
			{
				visited[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}

	return (visited[dest] == true);
}

int fordFulkerson(const vector<vector<int> >& graph, int s, int t)
{
	// define residual graph
	int n = graph.size();
	vector<vector<int> > rgraph(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			rgraph[i][j] = graph[i][j];
		}
	}
	int maxFlow = 0;

	while (true)
	{
		deque<bool> visited(n, false);
		vector<int> parent(n, -1);
		// find argument path s->t
		int pathFlow = INT_MAX;
		if (bfs(rgraph, visited, parent, s, t))
		{
			// find the minimum capacity
			for (int v = t; v != s; v = parent[v])
			{
				int u = parent[v];
				pathFlow = min(pathFlow, rgraph[u][v]);
			}
			// update residual graph
			for (int v = t; v != s; v = parent[v])
			{
				int u = parent[v];
				rgraph[u][v] -= pathFlow;
				rgraph[v][u] += pathFlow;
			}
			
			// update maxFlow
			maxFlow += pathFlow;

		}
		else
		{
			break;
		}
	}

	return maxFlow;
}

int main()
{
	int n = 6;
	vector<vector<int> > graph(n, vector<int>(n, 0));
	graph[0][1] = 16; graph[0][2] = 13;
	graph[1][2] = 10; graph[1][3] = 12;
	graph[2][1] = 4; graph[2][4] = 14;
	graph[3][2] = 9; graph[3][5] = 20;
	graph[4][3] = 7; graph[4][5] = 4;
	
	int ans = fordFulkerson(graph, 0, 5);

	cout << "Max Flow: " << ans << endl;
	return 0;
}
