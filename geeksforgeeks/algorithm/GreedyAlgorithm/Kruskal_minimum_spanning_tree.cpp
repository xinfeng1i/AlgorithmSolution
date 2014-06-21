#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Edge
{
	int src;
	int dest;
	int weight;
	Edge(int s, int e, int w):src(s), dest(e), weight(w){}
};

bool cmpEdge(const Edge& a, const Edge& b)
{
	if (a.weight != b.weight)
	{
		return a.weight < b.weight;
	}
	else if (a.src != b.src)
	{
		return a.src < b.src;
	}
	else
	{
		return a.dest < b.dest;	
	}	
}

class Graph
{
private:
	int V;
	int E;
	vector<Edge> edges;

private:
	vector<int> parent;
	int FIND(int x);
	void UNION(int u, int v);
public:
	Graph(int v, int e);
	void addEdge(int s, int e, int w);
	void addEdge(const Edge& e);
	vector<Edge> KruskalMST();
};

Graph::Graph(int v, int e):V(v), E(e)
{
	edges.reserve(e);	
	parent.resize(V);
	for (size_t i = 0; i < V; ++i) parent[i] = i;
}
int Graph::FIND(int x)
{
	while (parent[x] != x) x = parent[x];
	return x;
}
void Graph::UNION(int u, int v)
{
	int x = FIND(u);
	int y = FIND(v);
	parent[x] = y;
}

void Graph::addEdge(int s, int e, int w)
{
	Edge tmp(s, e, w);
	edges.push_back(tmp);
}

void Graph::addEdge(const Edge& e)
{
	edges.push_back(e);
}

vector<Edge> Graph::KruskalMST()
{
	vector<Edge> myedges(edges.begin(), edges.end());
	sort(myedges.begin(), myedges.end(), cmpEdge);

	vector<Edge> ans;
	for (size_t i = 0; i < myedges.size(); ++i)
	{
		int u = myedges[i].src;
		int v = myedges[i].dest;
		if (FIND(u) != FIND(v))
		{
			ans.push_back(myedges[i]);
			UNION(u, v);
		}
	}
	
	return ans;
}
/*
 * Time Complexity: O(ElogE) OR O(ElogV) 
 */

int main()
{
	Graph g(4, 5);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);

	vector<Edge> ans = g.KruskalMST();

	cout << "The minimum spanning tree edges are:" << endl;
	for (size_t i = 0; i < ans.size(); ++i)
	{
		cout << ans[i].src << "---" << ans[i].dest << endl;
	}
	cout << endl;

	return 0;
}
