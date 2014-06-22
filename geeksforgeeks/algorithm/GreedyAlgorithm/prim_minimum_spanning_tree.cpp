#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define INF 10000

int findMinKey(bool visited[], const vector<int>& key)
{
	int min_key = INF;
	int min_index = -1;
	
	for (int i = 0; i < key.size(); ++i)
	{
		if (!visited[i] && key[i] < min_key)
		{
			min_key = key[i];
			min_index = i;
		}
	}

	return min_index;
}

// adjacent matrix representation
void PrimMST(const vector<vector<int> >& graph, int src)
{	
	int n = graph.size();
	bool visited[n];
	vector<int> parent(n, -1);
	vector<int> key(n, INF);
	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
	}

	key[src] = 0;		

	for (int cnt = 0; cnt < n; ++cnt)
	{
		int u = findMinKey(visited, key);
		visited[u] = true;
		for (int v = 0; v < n; ++v)
		{
			if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v])
			{
				key[v] = graph[u][v];	
				parent[v] = u;
			}
		}
	}

	// print
	cout << "The Prim Minimum spanning tree is : " << endl;
	for (int i = 1; i < n; ++i)
	{
		cout << parent[i] << " - " << i << " " << graph[parent[i]][i] << endl;
	}
	cout << endl;

	return;
}


int main()
{
	vector<vector<int> > g(5, vector<int>(5, 0));
	g[0][1] = 2; g[1][0] = 2;
	g[1][2] = 3; g[2][1] = 3;
	g[0][3] = 6; g[3][0] = 6;
	g[1][3] = 8; g[3][1] = 8;
	g[1][4] = 5; g[4][1] = 5;
	g[2][4] = 7; g[4][2] = 7;
	g[3][4] = 9; g[4][3] = 9;

	PrimMST(g, 0);
	
	return 0;
}
