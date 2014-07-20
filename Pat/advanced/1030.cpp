#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 1E8;
vector<int> globalPath;
int globalCost = INF;

int findMinDist(vector<int> dist, vector<int> visited)
{
	int min = INF; int minIndex = -1;
	for (size_t i = 0; i < dist.size(); ++i)
	{
		if (!visited[i] && dist[i] < min)
		{
			min = dist[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void dfs_visit(int dest, int src, int curcost, vector<int> path,
		const vector<vector<int> >& parent,
		const vector<vector<int> >& cost)
{
	if (dest == src) 
	{
		path.push_back(dest);
		if (curcost < globalCost)
		{
			globalCost = curcost;
			globalPath.clear();
			for (size_t i = 0; i < path.size(); ++i)
			{
				globalPath.push_back(path[i]);
			}
		}
		return;
	}
	
	path.push_back(dest);
	for (size_t i = 0; i < parent[dest].size(); ++i)
	{
		int v = parent[dest][i];
		dfs_visit(v, src, cost[dest][v] + curcost, path, parent, cost);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<vector<int> > graph(n, vector<int>(n, INF));
	vector<vector<int> > cost(n, vector<int>(n, INF));

	int eds, ede, edw, edc;
	for (int i = 0; i < m; ++i)
	{
		cin >> eds >> ede >> edw >> edc;	

		graph[eds][ede] = edw;
		graph[ede][eds] = edw;
		cost[eds][ede] = edc;
		cost[ede][eds] = edc;
	}


	
	// Dijkstra Algorithm
	vector<vector<int> > parent(n);
	vector<int> dist(n, INF);	
	vector<int> visited(n, 0);
	dist[s] = 0;

	for (int i = 0; i < n; ++i)
	{
		// find the mindist node as current node
		int u = findMinDist(dist, visited);
		// visit the current node
		visited[u] = 1;

		// update all its neighbors
		for (int v = 0; v < n; ++v)
		{
			if (graph[u][v] != INF && !visited[v] && dist[u] != INF
					&& dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
				parent[v].clear();
				parent[v].push_back(u);
			}
			else if (graph[u][v] != INF && !visited[v] && dist[u] != INF
					&& dist[u] + graph[u][v] == dist[v])
			{
				parent[v].push_back(u);
			}
		}
	}

	vector<int> path;
	dfs_visit(d, s, 0, path, parent, cost);

	bool isFirst = true;
	for (auto it = globalPath.rbegin(); 
			it != globalPath.rend(); ++it)
	{
		if (isFirst) isFirst = false;
		else cout << " ";

		cout << *it; 
	}
	cout << " " << dist[d] << " " << globalCost << endl;


	return 0;	

}
