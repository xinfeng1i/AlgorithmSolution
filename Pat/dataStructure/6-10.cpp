#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 3000000;
const int NIL = -1;
vector<vector<int> > globalPath;

struct Edge
{
	int start_;
	int end_;
	int weight_;
	int order_;

	Edge(int s, int e):start_(s), end_(e), weight_(0)
	{}
	Edge()
	{}

	bool operator<(const Edge& other) const
	{
		if (start_ != other.start_) return start_ < other.start_;
		else return other.order_ < order_;
	}
};

bool BellmanFord(int n, const vector<Edge>& edges, int src, vector<int>& dist, vector<set<int> >& parent)
{
	dist.resize(n); 
	for (int i = 0; i < n; ++i) dist[i] = INF; 
	dist[src] = 0;
	parent.resize(n); 
	for (int i = 0; i < n; ++i) parent[i].clear();

	for (int i = 0; i < n - 1; ++i)
	{
		vector<Edge>::iterator it;
		for (auto it = edges.begin(); it != edges.end(); ++it)
		{
			int u = it->start_;
			int v = it->end_;
			int w = it->weight_;
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				parent[v].clear();
				dist[v] = dist[u] + w;	
				parent[v].insert(u);
			}
			else if (dist[u] != INF && dist[u] + w == dist[v])
			{
				parent[v].insert(u);
			}
		}
	}

	// ONE MORE TIME to check negative loop
	for (auto it = edges.begin(); it != edges.end(); ++it)
	{
		int u = it->start_;
		int v = it->end_;
		int w = it->weight_;
		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			return true;
		}
	}
	return false;
}

void printPath(int dest, int src, const vector<set<int> >& parent, vector<int> path)
{
	if (dest == src)
	{
		path.push_back(dest);
		/*
		for (auto it = path.rbegin(); it != path.rend(); ++it)
		{
			printf(" %d", *it + 1);
		}
		printf("\n");
		*/
		globalPath.push_back(path);
	}
	else 
	{
		path.push_back(dest);
		for (auto it = parent[dest].begin(); it != parent[dest].end(); ++it)
		{
			printPath(*it, src, parent, path);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int s, e, w;

	vector<Edge> edges(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e >> w;
		edges[i].start_ = s - 1;
		edges[i].end_ = e - 1;
		edges[i].weight_ = -w;
		edges[i].order_ = i;
	}

	vector<int> minSrc;
	int minDist = INF;

	vector<int> dist;
	vector<set<int> > parent;
	for (int src = 0; src < n; ++src)
	{
		int curMinDist = INF;
		bool flag = BellmanFord(n, edges, src, dist, parent);
		if (flag == true)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (dist[i] < curMinDist)
				{
					curMinDist = dist[i];
				}
			}
		}
		if (curMinDist < minDist)
		{
			minSrc.clear();
			minDist = curMinDist;
			minSrc.push_back(src);
		}
		else if (curMinDist == minDist)
		{
			minSrc.push_back(src);
		}
	}

	int globalMinDist = INF;
	for (size_t k = 0;  k < minSrc.size(); ++k)
	{
		BellmanFord(n, edges, minSrc[k], dist, parent);
		int minDest = INF;
		for (int i = 0; i < n; ++i)
		{
			if (dist[i] < minDest) minDest = i;
		}

		vector<int> path; path.clear();
		printPath(minDest, minSrc[k], parent, path);

		globalMinDist = dist[minDest];
	}

	cout << -globalMinDist << endl;
	set<Edge> keyLinks;
	for (size_t i = 0; i < globalPath.size(); ++i)
	{
		for (size_t j = 0; j + 1 < globalPath[i].size(); ++j)
		{
			
			Edge tmp;
			tmp.start_ = globalPath[i][j+1];
			tmp.end_ = globalPath[i][j];
			for (int order = 0; order < m; ++order)
			{
				if (edges[order].start_ == tmp.start_ &&
					edges[order].end_ == tmp.end_)
				{
					tmp.order_ = order;
				}
			}
			keyLinks.insert(tmp);
			//cout << globalPath[i][j+1]+1 << " - " << globalPath[i][j]+1 << endl;
		}
	}

	//cout << "ans " << endl;
	for (auto it = keyLinks.begin(); it != keyLinks.end(); ++it)
	{
		cout << it->start_+1 << "->" << it->end_+1 << endl;
	}
	
	return 0;
}
