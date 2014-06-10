#include <iostream>
#include <string>
#include <list>
#include <stack>
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
	void topologicalSortFrom(int u, bool visited[], stack<int>& curStack);
	void topologicalSort();
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
}

void Graph::topologicalSortFrom(int u, bool visited[], stack<int>& curStack)
{
	// visit current node
	visited[u] = true;

	// recur for all its neighbor
	list<int>::iterator it;
	for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
	{
		int v = *it;
		if (!visited[v])
		{
			topologicalSortFrom(v, visited, curStack);
		}
	}

	// push current node to stack
	curStack.push(u);
}


void Graph::topologicalSort()
{
	bool visited[V];
	for (int i = 0; i < V; ++i) visited[i] = false;
	stack<int> curStack;

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
		{
			topologicalSortFrom(i, visited, curStack);
		}
	}

	cout << "the topological sort is : " << endl;
	while (!curStack.empty())
	{
		cout << " " << curStack.top();
		curStack.pop();
	}
	cout << endl;
}
/* time complexity: O(V+E) */


int main()
{
	Graph g1(6);
	g1.addEdge(5,2);
	g1.addEdge(5,0);
	g1.addEdge(4,1);
	g1.addEdge(4,0);
	g1.addEdge(2,3);
	g1.addEdge(3,1);
	
	g1.topologicalSort();

	return 0;
}
