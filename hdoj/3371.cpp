#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

// Minimum Spaning Tree with Kruskal algorithm
// Union-Find Data Structure
struct Edge {
	int u;
	int v;
	int cost;
	bool operator<(const Edge& other) const {
		if (cost != other.cost) {
			return cost < other.cost;
		} else if (u != other.u) {
			return u < other.u;
		} else {
			return v < other.v;
		}
	}
};

const int MAXN = 510;
int parent[MAXN];
int weight[MAXN];
int totEdge = 0;

void Init(int n)
{
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
		weight[i] = 1;
	}
	totEdge = 0;
}

// find
int Find(int x) {
	if (parent[x] == x) {
		return x;
	} else {
		int temp = Find(parent[x]);
		parent[x] = temp;
		return temp;
	}
}

// union by weight
void Union(int x, int y) {
	int rootx = Find(x);
	int rooty = Find(y);
	if (rootx != rooty) {
		if (weight[rootx] >= weight[rooty]) {
			parent[rooty] = rootx;
			weight[rootx] += weight[rooty];
		} else {
			parent[rootx] = rooty;
			weight[rooty] += weight[rootx];
		}
		totEdge += 1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int nCase = 0;
	scanf("%d", &nCase);
	for (int ca = 0; ca < nCase; ++ca) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		vector<Edge> edges(m);
		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
		}

		Init(n);
		int ans = 0;
		int t; int src; int dest;
		for (int i = 0; i < k; ++i) {
			scanf("%d", &t);
			for (int j = 0; j < t; ++j) {
				if (j == 0) {
					scanf("%d", &src);
				} else {
					scanf("%d", &dest);
					Union(src, dest);
				}
			}
		}

		sort(edges.begin(), edges.end());
		for (size_t i = 0; i < edges.size() && totEdge < n-1; ++i) {
			int a = edges[i].u;
			int b = edges[i].v;
			int c = edges[i].cost;
			int roota = Find(a);
			int rootb = Find(b);
			if (roota == rootb) {
				continue;
			} else {
				Union(roota, rootb);
				ans += c;
			}
		}

		if (totEdge == n-1) {
			printf("%d\n", ans);
		} else {
			printf("-1\n", ans);
		}
		
	}
	return 0;
}