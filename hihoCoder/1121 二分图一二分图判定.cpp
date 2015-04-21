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
using namespace std;

bool DFS(int src, vector<int>& color, const vector<vector<int>>& graph)
{
	// assert src have been colored
	for (int i = 0; i < graph[src].size(); ++i)
	{
		int v = graph[src][i];
		if (color[v] == -1)
		{
			color[v] = 1 - color[src];
			if (!DFS(v, color, graph))
			{
				return false;
			}
		}
		else if (color[v] == color[src])
		{
			return false;
		}

	}
	return true;
}

void solve()
{
	int N, M;
	cin >> N >> M;
	//vector<vector<int>> graph(N, vector<int>(N, 0));
	vector<vector<int>> graph(N);
	vector<int> color(N, -1);

	int u, v;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		//graph[u-1][v-1] = 1;
		//graph[v-1][u-1] = 1;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}

	for (int i = 0; i < N; ++i)
	{
		if (color[i] == -1)
		{
			color[i] = 0;
			if (!DFS(i, color, graph))
			{
				cout << "Wrong" << endl;
				return;
			}
		}
	}
	cout << "Correct" << endl;
	return;
}

// 使用邻接矩阵超时；使用邻接表AC
int main()
{
	freopen("data.in", "r", stdin);
	int T = 0; 
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		solve();
	}
	return 0;
}
