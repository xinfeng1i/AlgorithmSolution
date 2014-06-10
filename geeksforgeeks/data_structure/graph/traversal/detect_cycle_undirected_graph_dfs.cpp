#include <iostream>
#include <string>
#include <list>
using namespace std;

class Graph
{
private:
	int V;
	list<int>* adjList;
public:
	Graph(int n);
	~Graph();
	void addEdge(int u, int v);
	bool isCyclicFrom(int u, bool visited[], int parent);
	bool isCyclic();
};

Graph::Graph(int n):V(n)
{
	adjList = new list<int>[n];
}

Graph::~Graph()
{
	delete[] adjList;
}

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

bool Graph::isCyclicFrom(int u, bool visited[], int parent)
{
	visited[u] = true;
	list<int>::iterator it;
	for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
	{
		int v = *it;
		if (!visited[v])
		{
			if (isCyclicFrom(v, visited, u)) return true;
		}
		else
		{
			if (v != parent) return true;
		}
	}

	return false;
}

bool Graph::isCyclic()
{
	bool visited[V];

	for (int i = 0; i < V; ++i) visited[i] = false;
	
	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
		{
			if (isCyclicFrom(i, visited, -1)) return true;
		}
	}

	return false;
}

int main()
{
	Graph g1(5);
	g1.addEdge(0,1);
	g1.addEdge(0,2);
	g1.addEdge(0,3);
	g1.addEdge(1,2);
	g1.addEdge(3,4);
	bool ans1 = g1.isCyclic();
	if (ans1) cout << "Contain Cycles" << endl;
	else cout << "Not contain cycles" << endl;
	
	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	bool ans2 = g2.isCyclic();
	if (ans2) cout << "Contain Cycles" << endl;
	else cout << "Not contain cycles" << endl;
	return 0;
}
