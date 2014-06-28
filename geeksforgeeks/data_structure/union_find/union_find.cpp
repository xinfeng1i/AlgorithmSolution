#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/************************************************
 * Union Find data structure
 *
 * Two Main Improvement:
 * 1. union by rank
 * 2. path compression
 * 
 * Time Complexity O(\alpha * m)
 * \alpha denotes the inverse of the ACKerman function
 * m represents the number of basic operations (make-set, union, find)
 ************************************************/
const int N = 100;
int parent[N];
int rank[N];

void makeSet(int x)
{
	parent[x] = x;
	rank[x] = 0;
}

// path compression
int find(int x)
{
	if (x != parent[x])
	{
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

// union by rank
void union_(int x, int y)
{
	int u = find(x);
	int v = find(y);
	if (rank[u] < rank[v])
	{
		parent[u] = v;
	}
	else
	{
		parent[v] = u;
		if (rank[u] == rank[v])
		{
			rank[u]++;
		}
	}

}

/************************************************
 * Undirected Graph data structure
 ************************************************/
class Graph
{
private:
	int V;
	vector<vector<int> > adjMatrix;
	vector<int> visited;
public:
	Graph(int n);
	void addEdge(int u, int v);
	void dfs(int u);
	int getNodeNumber() { return V; }

	friend int main();
};

Graph::Graph(int n):V(n)
{
	adjMatrix.resize(n);
	for (int i = 0; i < n; ++i) adjMatrix[i].resize(n);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			adjMatrix[i][j] = 0;

	visited.resize(n);
	for (int i = 0; i < n; ++i) visited[i] = 0;
}

void Graph::addEdge(int u, int v)
{
	adjMatrix[u][v] = 1;
	adjMatrix[v][u] = 1;
}

void Graph::dfs(int u)
{
	visited[u] = 1;
	cout << " " << u << endl;
	for (int v = 0; v < V; ++v)
	{
		if (adjMatrix[u][v] != 0 && !visited[v])
		{
			dfs(v);
		}
	}
}


int main()
{
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(7, 8);

	/* use UNION FIND to find connected component */
	// init
	for (int i = 0; i < 10; ++i)
	{
		makeSet(i);
	}

	int n = g.getNodeNumber();
	// for every edge uv, if u, v not in the same tree, union them
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (g.adjMatrix[i][j] != 0)
			{
				if (find(i) != find(j))
				{
					union_(i, j);
				}
			}
		}
	}

	// output result using parent
	for (int i = 0; i < n; ++i)
	{
		cout << i << " root:" << find(i) << endl;
	}

	/* use dfs to find connected component */
	for (int i = 0; i < n; ++i)
	{
		if (!g.visited[i])
		{
			cout << "A new compont" << endl;
			g.dfs(i);
		}
	}

	return 0;

}

