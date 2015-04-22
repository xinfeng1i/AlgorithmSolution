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

bool FindPath(int u, const vector<vector<int>>& graph, deque<bool>& checked, vector<int>& matched)
{
	for (size_t i = 0; i < graph[u].size(); ++i)
	{
		int v = graph[u][i];
		if (!checked[v])
		{
			checked[v] = true;
			if (matched[v] == -1 || FindPath(matched[v], graph, checked, matched))
			{
				matched[v] = u;
				matched[u] = v;
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	deque<bool> checked(N, false);
	vector<int> matched(N, -1);

	int u, v;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		checked.clear();
		checked.resize(N, false);
		if (matched[i] == -1)
		{
			if (FindPath(i, graph, checked, matched)) cnt++;
		}
	}

	cout << cnt << endl;
	cout << N - cnt << endl;
	return;
}

int main()
{
	freopen("data.in", "r", stdin);
	solve();
	return 0;
}