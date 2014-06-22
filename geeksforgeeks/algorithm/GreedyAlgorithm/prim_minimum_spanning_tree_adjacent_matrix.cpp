#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define INF 10000

struct Node
{
	int dest_;
	int weight_;
	Node(int dest, int weight):dest_(dest),
							   weight_(weight)
	{}
};

struct HeapNode
{
	int key_;
	int ID_;
	HeapNode(int key, int ID):key_(key), ID_(ID){}
	bool operator< (const HeapNode& other) const
	{
		if (key_ != other.key_) return key_ < other.key_;
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
	void addEdge(int src, int dest, int weight);
	void PrimMinimumSpanningTree(int src);
};

Graph::Graph(int n):V(n)
{
	adjList = new list<Node>[n];
}

void Graph::addEdge(int src, int dest, int weight)
{
	adjList[src].push_back(Node(dest, weight));
	adjList[dest].push_back(Node(src, weight));
}

void Graph::PrimMinimumSpanningTree(int src)
{
	vector<int> parent(V, -1);
	vector<int> key(V, INF);
	key[src] = 0;
	set<HeapNode> pq;  // use set as a priority_queue
	for (int i = 0; i < V; ++i)
	{
		HeapNode tmp(key[i], i);	
		pq.insert(tmp);
	}

	while (!pq.empty())
	{
		// extract the min element	
		int u = pq.begin()->ID_;
		pq.erase(pq.begin());

		list<Node>::iterator it;
		for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
		{
			Node vNode = *it;
			int v = vNode.dest_; int uv = vNode.weight_;

			HeapNode vHeapNode(key[v], v);
			if (pq.count(vHeapNode) == 1 && key[v] > uv)
			{
				// decrease key in another way
				pq.erase(vHeapNode);
				pq.insert(HeapNode(uv, v));
				key[v] = uv;
				parent[v] = u;
			}
		}
	}

	cout << "The prim spanning tree is:" << endl;
	for (int i = 0; i < V; ++i)
	{
		if (i != src)
		{
			int v = i;
			int u = parent[v];
			int weight = -1;
			list<Node>::iterator it;
			for (it = adjList[u].begin(); it != adjList[u].end(); ++it)
			{
				if (it->dest_ == v) weight = it->weight_;
			}
			cout << u << "-" << v << " " << weight << endl;
		}
	}

	return;
}

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

	g.PrimMinimumSpanningTree(0);
	return 0;
}
