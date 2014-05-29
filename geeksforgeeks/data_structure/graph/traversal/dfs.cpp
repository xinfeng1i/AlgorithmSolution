#include <iostream>
#include <string>
#include <list>
using namespace std;

/* 
 * 深度优先遍历
 * 一条道走到黑 再重新选择一条道再走到黑，再选择
 * 具体来说：
 * 选择当前节点，访问；对于其每个未被访问过的邻居，递归；
 */

class Graph
{
private:
	int V;
	list<int> *adjList;
	void dfsUntil(int src, bool visited[]);
public:
	Graph(int n):V(n)
	{
		adjList = new list<int>[n];
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}

	// 遍历以src开始的连通分支
	void dfs(int src);
	
	// 遍历整个图，即便图是不连通的
	void dfsGraph();
};


void Graph::dfsUntil(int src, bool visited[])
{
	visited[src] = true;
	cout << " " << src;

	list<int>::iterator it;
	for (it = adjList[src].begin(); it != adjList[src].end(); ++it)
	{
		int v = *it;
		if (!visited[v])
		{
			dfsUntil(v, visited);
		}
	}
}
void Graph::dfs(int src)
{
	bool visited[V];
	for (int i = 0; i < V; ++i) visited[i] = false;

	dfsUntil(src, visited);
}

void Graph::dfsGraph()
{
	bool visited[V];
	for (int i = 0; i < V; ++i) visited[i] = false;

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
		{
			dfsUntil(i, visited);
		}
	}
}
/* 复杂度分析：
 * 时间复杂度 O(E+V)
 * 需要遍历所有的顶点和所有的边一遍
 */

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "The dfs traversal of the graph is:" << endl;
	//g.dfs(2);
	g.dfsGraph();
	cout << endl;

	return 0;
}



