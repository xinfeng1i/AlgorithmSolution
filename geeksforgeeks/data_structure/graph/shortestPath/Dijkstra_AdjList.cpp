#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 3000000;
const int NIL = -1;

struct Node
{
	int dest_;
	int weight_;
	Node(int d, int w):dest_(d),weight_(w)
	{}
};

class Graph
{
private:
	int V_;
	list<Node>* adjList_;
public:
	Graph(int n):V_(n)
	{
		adjList_ = new list<Node>[n];
	}

	void addEdge(int u, int v, int w)
	{
		adjList_[u].push_back(Node(v, w));
		adjList_[v].push_back(Node(u, w)); // for undirected graph
	}
public:
	friend void Dijkstra(const Graph& g, int src);
};

void printPath(int dest, vector<int> parent)
{
	if (parent[dest] == NIL)
	{
		printf(" %d", dest); 
	}
	else
	{
		printPath(parent[dest], parent);
		printf(" %d", dest);
	}
}

// Time Complexity:
//
// INSERT all the nodes into pq, V * O(logV);
// EXTRACT MIN KEY for all the nodes, V * O(1);
// DECREASE KEY for all the edges, E * O(logV);
// TOTAL: O((V + E)logV);
//
// Can be reduced to O(E+VlogV) using Fibonacci Heap
// Cause DECREASE KEY only cost O(1)

void Dijkstra(const Graph& g, int src)
{
	int n = g.V_;	
	// INIT
	vector<int> dist(n, INF); dist[src] = 0;
	vector<int> parent(n, NIL);

	set<pair<int, int> > pq;
	for (int i = 0; i < n; ++i)
	{
		pq.insert(make_pair(dist[i], i));
	}

	// CORE Algorithm
	while (!pq.empty())
	{
		int u = pq.begin()->second;
		pq.erase(pq.begin());

		for (auto it = g.adjList_[u].begin(); it != g.adjList_[u].end(); ++it)
		{
			int v = it->dest_;
			int w = it->weight_;
			if (pq.count(make_pair(dist[v], v)) == 1 && dist[u] + w < dist[v])
			{
				pq.erase(make_pair(dist[v], v));	
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.insert(make_pair(dist[v], v));
			}
		}
	}

	// OUTPUT
	for (int i = 0; i < n; ++i)
	{
		cout << src << "-" << i << " : ";
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		printPath(i, parent);
		printf("\n");
	}

	return;
}


int main()
{
	int n = 9; int src = 0;
	Graph g(n);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	Dijkstra(g, src);
	return 0;
}
