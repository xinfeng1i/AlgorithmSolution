#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Edge;

class Graph
{
private:
	int V;
	int E;
	vector<Edge> edges;
public:
	Graph(int v,int e):V(v),E(e)
	{}

	void addEdge(int u, int v)
	{
		edges.push_back(make_pair(u, v));	
	}

	// find the deepest parent of u
	int Find(int parent[], int u)
	{
		if (parent[u] == -1) return u;
		else Find(parent, parent[u]);
	}

	// union the two branches
	int Union(int parent[], int u, int v)
	{
		int uparent = Find(parent, u);
		int vparent = Find(parent, v);
		parent[uparent] = vparent;
	}

	/*
	 * 基本思想
	 * 利用并查集unionfind，每次选择一条边，把两个不连通的分支连接起来
	 * 如果图不含有回路，那么是一颗树，最多n-1条边后，能够将整个图连接起来
	 * 否则，在任意时刻，如果一条边连接同一连通分支内的两个点，则必有回路
	 */
	bool isCyclic()
	{
		// init
		int* parent = new int[V];
		for (int i = 0; i < V; ++i) parent[i] = -1;

		for (int e = 0; e < edges.size(); ++e)
		{
			Edge edge = edges[e];
			int src = edge.first;
			int dest = edge.second;

			if (Find(parent, src) == Find(parent, dest))
			{
				return true;
			}
			else
			{
				Union(parent, src, dest);
			}
		}

		return false;
	}
};

int main()
{
	/*
	 *   0
	 * |   \
	 * |    \
	 * 1-----2
	 */

	Graph g(3, 3);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	
	/*
	Graph g(3, 2);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	*/

	bool ans = g.isCyclic();
	if (ans) cout << "Graph has cycles" << endl;
	else cout << "Graph doesn't have cycles" << endl;

	return 0;
}
