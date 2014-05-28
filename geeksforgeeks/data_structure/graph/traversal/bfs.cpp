#include <iostream>
#include <string>
#include <list>
#include <queue>
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
	void AddEdge(int u, int v)
	{
		adjList[u].push_back(v);
	}
	void bfs(int src);
};

/*
 * 广度优先遍历：
 * 需要辅助数据结构队列，首先访问源节点src, src进队；
 * 如果队列非空，取出队首元素u，对于u的每一个邻居近点v
 * 如果v未被访问过，访问v，进队
 */

/* 
 * 算法时间复杂度: O(V + E)
 * 因为对于每一个顶点都需要遍历所有的边
 */

void Graph::bfs(int src)
{
	queue<int> q;
	bool visited[V];
	for (int i = 0; i < V; ++i) visited[i] = false;

	visited[src] = true;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front();
		cout << " " << u;
		q.pop();

		for (list<int>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it)
		{
			int v = *it;
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int main()
{
	Graph g(4);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "The BFS traversal starting from vertex 2 is: " << endl;
	g.bfs(2);
	return 0;
}