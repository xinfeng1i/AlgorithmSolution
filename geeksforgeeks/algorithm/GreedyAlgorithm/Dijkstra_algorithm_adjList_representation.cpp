#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 10000;

struct Node
{
	int dest_;
	int weight_;
	Node(int dest, int w):dest_(dest), weight_(w){}
};

struct HeapNode
{
	int dist_;
	int ID_;
	HeapNode(int dist, int id):dist_(dist), ID_(id){}

	bool operator< (const HeapNode& other) const
	{
		if (dist_ != other.dist_) return dist_ < other.dist_;
		else return ID_ < other.ID_;
	}
};

class Graph
{
private:
	int V;
	list<Node>* adjList;
public:
	Graph(int n);
	void addEdge(int u, int v, int weight);
	void Dijkstra(int src);
};

Graph::Graph(int n):V(n)
{
	adjList = new list<Node>[n];
}

void Graph::addEdge(int u, int v, int weight)
{
	adjList[u].push_back(Node(v, weight));
	adjList[v].push_back(Node(u, weight));
}

void Graph::Dijkstra(int src)
{
	// init
	vector<int> visited(V, 0);
	vector<int> dist(V, INF);
	dist[src] = 0;

	// init heap
	set<HeapNode> q;
	for (int i = 0; i < V; ++i)
	{
		q.insert(HeapNode(dist[i], i));
	}

	while (!q.empty())
	{
		HeapNode tmp = *(q.begin());
		q.erase(q.begin());
		int u = tmp.ID_;
		visited[u] = 1;

		list<Node>::iterator it;
		for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
		{
			int v = it->dest_;
			int uv = it->weight_;
			if (!visited[v] && dist[u] + uv < dist[v])
			{
				// decrease key in heap
				q.erase(HeapNode(dist[v], v));
				dist[v] = dist[u] + uv;
				q.insert(HeapNode(dist[v], v));
			}
		}
	}

	cout << "the Dijkstra shortest path is:" << endl;
	for (int i = 0; i < V; ++i)
	{
		cout << src << " - " << i << " : " << dist[i] << endl;
	}
	cout << endl;

	return;
}
/* Time Complexity:
 * like BFS have O(V+E), but the decrease key operation cost O(logV)
 * so we have O((V+E)log(V)) = O(ElogV)
 */

int main()
{
	Graph g(9);
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

	g.Dijkstra(0);

	return 0;
}
