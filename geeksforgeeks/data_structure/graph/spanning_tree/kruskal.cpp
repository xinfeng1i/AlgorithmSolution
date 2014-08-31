#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> parent;
vector<int> myrank;

void MakeSet(int x)
{
	parent[x] = x;
	myrank[x] = 0;
}

int Find(int x)
{
	if (x != parent[x])
	{
		parent[x] = Find(parent[x]);
	}
	return parent[x];
}

void Union(int rootx, int rooty)
{
	if (myrank[rootx] < myrank[rooty])
	{
		parent[rootx] = rooty;
	}
	else
	{
		parent[rooty] = rootx;
		if (myrank[rooty] == myrank[rootx])
		{
			myrank[rootx] += 1;
		}
	}
}

struct Edge
{
	int src_;
	int dest_;
	int weight_;

	Edge(int s, int e, int w):src_(s), dest_(e), weight_(w)
	{}

	bool operator<(const Edge& other) const
	{
		if (weight_ != other.weight_)
			return weight_ < other.weight_;
		else
			return src_ < other.src_;
	}
};

bool cmpEdge(const Edge& a, const Edge& b)
{
	if (a.weight_ != b.weight_)
	{
		return a.weight_ < b.weight_;
	}
	else
	{
		return a.src_ < b.src_;
	}
}

class Graph
{
public:
	int V_;
	int E_;
	vector<Edge> edges_;
};

int Kruskal(Graph& g, vector<Edge>& ans)
{
	int cnt = 0;
	int weight = 0;
	sort((g.edges_).begin(), (g.edges_).end());
	myrank.resize(g.V_);
	parent.resize(g.V_);
	for (int i = 0; i < g.V_; ++i)
	{
		myrank[i] = 0;
		parent[i] = i;
	}

	for (size_t i = 0; i < g.edges_.size(); ++i)
	{
		Edge tmp = g.edges_[i];
		int s = tmp.src_;
		int e = tmp.dest_;
		int w = tmp.weight_;
		int roots = Find(s);
		int roote = Find(e);
		if (roots != roote)
		{
			Union(roots, roote);
			cnt++;
			weight += w;
			ans.push_back(tmp);
		}
		if (cnt == g.V_ - 1)
		{
			break;
		}
	}
	return weight;
}

int main()
{
	Graph g;
	g.V_ = 4;
	g.E_ = 5;
	g.edges_.push_back(Edge(0, 1, 10));
	g.edges_.push_back(Edge(0, 2, 6));
	g.edges_.push_back(Edge(0, 3, 5));
	g.edges_.push_back(Edge(1, 3, 15));
	g.edges_.push_back(Edge(2, 3, 4));

	vector<Edge> ans;
	int weight = Kruskal(g, ans);

	cout << "the minimum weight of spanning tree is:" << weight << endl;
	for (size_t i = 0; i < ans.size(); ++i)
	{
		cout << "Edge: " << ans[i].src_ << " - " << ans[i].dest_ << endl;
	}

	Graph g2;
	g2.V_ = 9;
	g2.E_ = 14;
	g2.edges_.push_back(Edge(0, 1, 4));
	g2.edges_.push_back(Edge(0, 7, 8));
	g2.edges_.push_back(Edge(1, 7, 11));
	g2.edges_.push_back(Edge(1, 2, 8));
	g2.edges_.push_back(Edge(2, 8, 2));
	g2.edges_.push_back(Edge(6, 8, 6));
	g2.edges_.push_back(Edge(6, 7, 1));
	g2.edges_.push_back(Edge(7, 8, 7));
	g2.edges_.push_back(Edge(2, 3, 7));
	g2.edges_.push_back(Edge(2, 5, 4));
	g2.edges_.push_back(Edge(5, 6, 2));
	g2.edges_.push_back(Edge(3, 5, 14));
	g2.edges_.push_back(Edge(3, 4, 9));
	g2.edges_.push_back(Edge(4, 5, 10));
	vector<Edge> ans2;
	int weight2 = Kruskal(g2, ans2);

	cout << "the minimum weight of spanning tree is:" << weight2 << endl;
	for (size_t i = 0; i < ans2.size(); ++i)
	{
		cout << "Edge: " << ans2[i].src_ << " - " << ans2[i].dest_ << endl;
	}

	return 0;
}
