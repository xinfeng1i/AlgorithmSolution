#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const long MAX_N = 100000 + 10;
const long MAX_M = 1000000 + 10;
long N; 
long M;

long myrank[MAX_N];
long parent[MAX_N];

void MakeSet()
{
	for (long i = 0; i < MAX_N; ++i)
	{
		parent[i] = i;
		myrank[i] = 1;
	}
}

long myFind(long x)
{
	// path compression
	if (parent[x] == x) return x;
	parent[x] = myFind(parent[x]);
	return parent[x];
}

void myUnion(long x, long y)
{
	long rootx = myFind(x);
	long rooty = myFind(y);
	if (rootx != rooty)
	{
		// Union according to rank
		if (myrank[rootx] < myrank[rooty])
		{
			parent[rootx] = rooty;
		}
		else
		{
			parent[rooty] = rootx;
			if (myrank[rootx] == myrank[rooty])
			{
				myrank[rootx] += 1;
			}
		}
	}
}



struct Edge
{
	long start;
	long end;
	long weight;

	bool operator<(const Edge& other) const
	{
		if (weight != other.weight) return weight < other.weight;
		else if (start != other.start) return start < other.start;
		else return end < other.end;
	}
};

int main()
{
	freopen("data.in", "r", stdin);
	cin >> N >> M;
	long u, v, w;

	vector<Edge> edges(M);
	for (long i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		edges[i].start = u;
		edges[i].end = v;
		edges[i].weight = w;
	}

	sort(edges.begin(), edges.end());

	MakeSet();
	long long ans = 0;
	for (long i = 0; i < M; ++i)
	{
		u = edges[i].start;
		v = edges[i].end;
		w = edges[i].weight;
		if (myFind(u) != myFind(v))
		{
			myUnion(u, v);
			ans += w;
		}
	}
	cout << ans << endl;

	return 0;
}