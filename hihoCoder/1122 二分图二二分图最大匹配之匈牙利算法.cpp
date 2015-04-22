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
	for (int i = 0; i < graph[u].size(); ++i)
	{
		int v = graph[u][i];
		if (!checked[v])
		{
			checked[v] = true;
			if (matched[v] == -1 || FindPath(matched[v], graph, checked, matched))
			{
				matched[u] = v;
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int solve()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	int u, v;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}

	vector<int> matched(N, -1);
	deque<bool> checked(N, false);

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

	//for (int i = 0; i < N; ++i)
	//{
	//	cout << "matched " << i + 1 << " " << matched[i] + 1 << endl;
	//}
	return cnt;
}

int main()
{
	freopen("data.in", "r", stdin);
	int ans = solve();
	cout << ans << endl;
	return 0;
}