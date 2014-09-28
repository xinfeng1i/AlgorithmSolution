#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long llong;
const long long INF = LLONG_MAX;

struct Edge
{
	int start_;
	int end_;
	llong weight_;

	Edge():start_(0), end_(0), weight_(0){}
	Edge(int s, int e, llong w):start_(s),end_(e),weight_(w){}

	bool operator< (const Edge& other) const
	{
		if (weight_ != other.weight_)
		{
			return weight_ < other.weight_;
		}
		else
		{
			if (start_ != other.start_) return start_ < other.start_;
			else return end_ < other.end_;
		}
	}
};

int main()
{
	int n;
	cin >> n;

	vector<vector<llong> > v(n, vector<llong>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	// check is symmetric
	bool isSymmetric = true;
	for (int i = 0; i < n; ++i)
	{
		if (v[i][i] != 0)
		{
			isSymmetric = false;
			break;
		}
		for (int j = i; j < n; ++j)
		{
			if (v[i][j] != v[j][i])
			{
				isSymmetric = false;
				break;
			}
		}
		if (isSymmetric == false)
		{
			break;
		}
	}

	if (!isSymmetric)
	{
		cout << "NO" << endl;
		return 0;
	}


	// find the smallest n-1 numbers, which is the edge of the tree
	vector<Edge> edges;	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			edges.push_back(Edge(i, j, v[i][j]));
		}
	}
	sort(edges.begin(), edges.end());
	edges.resize(n-1);
	
	// check the edges > 0
	bool hasNegativeEdge = false;
	for (size_t i = 0; i < n - 1; ++i)
	{
		if (edges[i].weight_ <= 0)
		{
			hasNegativeEdge = true;
			break;
		}
	}

	if (hasNegativeEdge)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	// check other edges
	vector<vector<llong> > path(n, vector<llong>(n,INF));
	for (size_t i = 0; i < edges.size(); ++i)
	{
		int s = edges[i].start_;
		int e = edges[i].end_;
		llong w = edges[i].weight_;
		path[s][e] = w;
		path[e][s] = w;
	}
	for (int i = 0; i < n; ++i) path[i][i] = 0;

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (path[i][k] != INF && path[k][j] != INF && 
					path[i][k] + path[k][j] < path[i][j])
				{
					path[i][j] = path[i][k] + path[k][j];
				}
			}
		}
	}
	
	// check equal
	bool isEqual = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (path[i][j] != v[i][j])
			{
				isEqual = false;
				break;
			}
		}
		if (isEqual == false) break;
	}

	if (isEqual) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
