#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adjList;
public:
	Graph(int n):V(n)
	{
		adjList = new list<int>[n];
	}
	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}

	bool isCyclicUntil(int u, bool visited[], bool recurStack[]);
	bool isCyclic();
};

/*
 * 判断从u开始的子图是否有环
 * 
 * 基本思想：
 * 访问当前点u, 并进栈；对于其每一个邻居，如果在递归栈中，那么有回
 * 边，直接返回有环；否则递归判断从邻居v开始的子图是否有环，如果有
 * 则直接返回有环。
 * 如果所有邻居都没有返回有环，则当前节点退栈，返回当前节点u开始的子图无环。
 */
bool Graph::isCyclicUntil(int u, bool visited[], bool recurStack[])
{
	// 当前节点进栈
	visited[u] = true;
	recurStack[u] = true;

	// 递归邻居节点
	list<int>::iterator it;
	for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
	{
		int v = *it;

		// 递归从邻居节点v开始的子图是否有环
		if (!visited[v] && isCyclicUntil(v, visited, recurStack))
		{
			return true;
		}
		else if (recurStack[v] == true) // 有回边
		{
			return true;
		} 

	}
	
	// 当前节点退栈
	recurStack[u] = false;

	return false;
}

bool Graph::isCyclic()
{
	bool visited[V];
	bool recurStack[V];

	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
		recurStack[i] = false;
	}

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
		{
			if (isCyclicUntil(i, visited, recurStack))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	/*
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	*/
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);

	if (g.isCyclic())
	{
		cout << "has cycle" << endl;
	}
	else
	{
		cout << "Not has cycle" << endl;
	}

	return 0;
}
