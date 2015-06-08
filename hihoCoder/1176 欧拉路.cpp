#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;

void DFS(const vector<vector<int> >& adjList, deque<bool>& visited, int src)
{
	visited[src] = true;
	for (size_t i = 0; i < adjList[src].size(); ++i)
	{
		int v = adjList[src][i];
		if (!visited[v])
		{
			DFS(adjList, visited, v);
		}
	}
}

bool HasEulerRoad(const vector<vector<int> >& adjList, const vector<int>& degree)
{
	// connected or not
	int n = adjList.size();
	deque<bool> visited(n, false);
	DFS(adjList, visited, 0);
	
	bool isConnected = true;
	for (size_t i = 0; i < visited.size(); ++i)
	{
		if (!visited[i])
		{
			isConnected = false;
			break;
		}
	}
	
	// not connected, no need to judge
	if (!isConnected) return false;
	
	int odd = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (degree[i] % 2 == 1) odd++;
	}
	
	if (odd == 2 || odd == 0) return true;
	else return false;
	
}

int main()
{
	freopen("data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > adjList(n);
	vector<int> degree(n, 0);
	int u, v;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		adjList[u-1].push_back(v-1);
		adjList[v-1].push_back(u-1);
		degree[u-1]++;
		degree[v-1]++;
	}
	
	bool ans = HasEulerRoad(adjList, degree);
	if (ans) cout << "Full" << endl;
	else cout << "Part" << endl;
	
	return 0;
}
