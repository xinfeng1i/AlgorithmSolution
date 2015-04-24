#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
using namespace std;

#if 1
const int INF = INT_MAX;
vector<int> SPFA(vector<vector<pair<int, int>>>& adjList, int src)
{
	int N = adjList.size();
	vector<int> dist(N, INF);
	dist[src] = 0;

	vector<int> q(10 * N);
	deque<bool> vst(N, false);
	q[0] = src;
	vst[src] = true;
	int q_pri = 0;
	int q_end = 1;
	
	while (q_pri < q_end)
	{
		int u = q[q_pri++];
		vst[u] = false;
		for (int i = 0; i < adjList[u].size(); ++i)
		{
			int v = adjList[u][i].first;
			int w = adjList[u][i].second;
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				if (!vst[v])
				{
					q[q_end++] = v;
					vst[v] = true;
				}
			}
		}
	}

	return dist;
}

void solve()
{
	int N, M, S, T;
	cin >> N >> M >> S >> T;

	vector<vector<pair<int, int>>> adjList(N);
	int u, v, w;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> w;
		adjList[u-1].push_back(make_pair(v-1, w));
		adjList[v-1].push_back(make_pair(u-1, w));
	}

	vector<int> dist = SPFA(adjList, S-1);
	cout << dist[T-1] << endl;
}

int main()
{
	freopen("data.in", "r", stdin);
	solve();
	return 0;
}
#endif //0