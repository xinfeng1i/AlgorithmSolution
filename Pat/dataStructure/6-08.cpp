#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 300000;
vector<stack<int> > allShortestPaths;

// find the minimum dist in the unvisited nodes
int minDist(vector<int>& dist, vector<int>& visited)
{
	int ans = INF, index;
	for (int i = 0; i < dist.size(); ++i)
	{
		if (!visited[i] && dist[i] < ans)
		{
			ans = dist[i];
			index = i;
		}
	}

	return index;
}

void printStack(stack<int> s)
{
	cout << "print stack: ";
	while (!s.empty())
	{
		cout << " " << s.top();
		s.pop();
	}
	cout << endl;
}

// print all the shortest path from s to d
void printPaths(vector<vector<int> > prev, int s, int d, stack<int>& path)
{
	path.push(d);

	if (d == s)
	{
		//printStack(path);
		allShortestPaths.push_back(path);
	}
	else
	{
		for (int i = 0; i < prev[d].size(); ++i)
		{
			printPaths(prev, s, prev[d][i], path);
		}
	}

	path.pop();
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	vector<int> rescueNum(n, 0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rescueNum[i]);
	}

	vector<vector<int> > graph(n, vector<int>(n, INF));
	int src, dest, weight;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &src, &dest, &weight);
		graph[src][dest] = weight;
		graph[dest][src] = weight;
	}

	// Dijkstra algo
	for (int i = 0; i < n; ++i)
	{
		graph[i][i] = 0;
	}
	vector<int> dist(n, INF);
	vector<int> visited(n, 0);
	dist[s] = 0;
	
	// record all the shortest paths
	vector<vector<int> > prev(n);

	for (int i = 0; i < n - 1; ++i)
	{
		int u = minDist(dist, visited);
		visited[u] = 1;
		for (int v = 0; v < n; ++v)
		{
			if (v != u && graph[u][v] != INF && dist[u] != INF && !visited[v])
			{
				if (dist[u] + graph[u][v] < dist[v])
				{
					prev[v].clear();
					dist[v] = dist[u] + graph[u][v];	
					prev[v].push_back(u);
				}
				else if (dist[u] + graph[u][v] == dist[v])
				{
					prev[v].push_back(u);
				}
			}
		}
	}
	
	/*
	cout << "dist:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << " " << dist[i];
	}
	cout << endl;
	cout << "prev:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "prev[" << i << "]:";
		for (int j = 0; j < prev[i].size(); ++j)
		{
			cout <<"  " <<  prev[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "shorstest paths: " << endl;
	*/
	stack<int> path;
	printPaths(prev,s,d, path); 

	int ans_rescueNum = -1;
	int ans_index;
	for (int i = 0; i < allShortestPaths.size(); ++i)
	{
		stack<int> path(allShortestPaths[i]);
		int cnt = 0;
		while (!path.empty())
		{
			cnt += rescueNum[path.top()];
			path.pop();
		}

		if (cnt > ans_rescueNum)
		{
			ans_rescueNum = cnt;
			ans_index = i;
		}
		
	}

	stack<int> ans_path(allShortestPaths[ans_index]);
	cout << allShortestPaths.size() << " " << ans_rescueNum << endl;
	bool isFirst = true;
	while (!ans_path.empty())
	{
		if (isFirst)
		{
			cout << ans_path.top();
			isFirst = false;
		}
		else
		{
			cout <<" " << ans_path.top();
		}
		ans_path.pop();
	}
	cout << endl;

	return 0;
}
