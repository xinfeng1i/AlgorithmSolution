/*
 * 图的表示
 *
 * 邻接矩阵
 * 优点：简单高效，增加、删除一条边需要O(1)的时间
 * 缺点：空间占用O(V^2)，增加一个顶点需要O(V)的时间
 *
 * 邻接表：
 * 优点：节省空间O(V+E)
 * 缺点：查询一条边u-v是否在图中非常低效
 */

 #include <iostream>
 #include <string>
 #include <vector>
 #include <cassert>
 using namespace std;

struct Node
{
	int dest;
	Node* next;
	Node(int v):dest(v), next(NULL){};
};

class Graph
{
private:
	int V;
	vector<Node*> adjList;
public:
	Graph(int n);
	~Graph();
	void AddEdge(int u, int v);
	void PrintGraph();
};

Graph::Graph(int n)
{
	assert(n >= 1);
	V = n;
	adjList.resize(V);
	for (int i = 0; i < V; ++i)
	{
		adjList[i] = NULL;
	}
}
Graph::~Graph()
{
	for (int i = 0; i < V; ++i)
	{
		while (adjList[i] != NULL)
		{
			Node* p = adjList[i];
			adjList[i] = adjList[i]->next;
			delete p;
			p = NULL;
		}
	}
}

void Graph::AddEdge(int u, int v)
{
	Node* pnewNode = new Node(v);
	pnewNode->next = adjList[u];
	adjList[u] = pnewNode;

	// 此处假设是无向图，每次加边都是对称的
	Node* pnewNodeU = new Node(u);
	pnewNodeU->next = adjList[v];
	adjList[v] = pnewNodeU;
}

void Graph::PrintGraph()
{
	cout << "The graph has " << V << " nodes" << endl;
	cout << "The adj list is:" << endl;
	for (int i = 0; i < V; ++i)
	{
		cout << "head " << i;
		for (Node* p = adjList[i]; p != NULL; p = p->next)
		{
			cout << "->" << p->dest;
		}
		cout << endl;
	}
}

int main()
{
	Graph g(5);
	g.AddEdge(0, 1);
	g.AddEdge(0, 4);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(1, 4);
	g.AddEdge(2, 3);
	g.AddEdge(3, 4);

	g.PrintGraph();
	return 0;
}