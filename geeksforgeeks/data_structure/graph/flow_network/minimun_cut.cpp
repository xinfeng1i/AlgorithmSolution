#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <functional>
using namespace std;

void dfs(const vector<vector<int> >& graph, int src, deque<bool>& visited)
{
	visited[src] = true;
	for (int v = 0; v < graph[src].size(); ++v)
	{
		if (graph[src][v] != 0 && !visited[v])
		{
			dfs(graph, v, visited);
		}
	}
}


// 利用bfs搜索从s到t的一条路径，如果能找到返回true
bool bfs(const vector<vector<int> >& rGraph, deque<bool>& visited, vector<int>& parent, int s, int t)
{
	queue<int> q;
	visited[s] = true;
	parent[s] = -1;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < rGraph[u].size(); ++v)
		{
			if (rGraph[u][v] != 0 && !visited[v])
			{
				visited[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}

	return visited[t] == true;
}

int maxFlow(const vector<vector<int> >& graph, int s, int t)
{
	int maxflow = 0;

	// 残留网络
	int n = graph.size();
	vector<vector<int> > rGraph(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			rGraph[i][j] = graph[i][j];
		}
	}

	while (true)
	{
		deque<bool> visited(n, false);
		vector<int> parent(n, -1);
		bool flag = bfs(rGraph, visited, parent, s, t);	
		if (!flag)
		{
			break;
		}

		// max capacity
		int minCapacity = INT_MAX;
		for (int v = t; parent[v] != -1; v = parent[v])
		{
			int u = parent[v];
			if (rGraph[u][v] < minCapacity)
			{
				minCapacity = rGraph[u][v];
			}
		}

		// update residual graph
		for (int v = t; parent[v] != -1; v = parent[v])
		{
			int u = parent[v];
			rGraph[u][v] -= minCapacity;
			rGraph[v][u] += minCapacity;
		}

		maxflow += minCapacity;

	}

	// dfs to find the cut between s and t
	deque<bool> visited(n, false);
	dfs(rGraph, s, visited);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] != 0 && visited[i] == true && visited[j] == false)
			{
				cout << i << "->" << j << endl;
			}
		}
	}

	return maxflow;
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
	
	int ans = maxFlow(graph, 0, 5);

	cout << "Max Flow: " << ans << endl;
	return 0;
}
