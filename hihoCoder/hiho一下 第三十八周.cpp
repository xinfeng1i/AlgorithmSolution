#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int N, M, K, T;
const int MAX_N = 10000;
long graph[MAX_N + 10][MAX_N + 10];
//vector<pair<int, long> > graph[MAX_N + 10];

bool canReachT(long x);
bool canReachTUtil(int src, int dest, long x, int cnt, deque<bool>& visited);

int main()
{
	freopen("data.in", "r", stdin);
	//cin >> N >> M >> K >> T;
	scanf("%d%d%d%d", &N, &M, &K, &T);
	int u, v; long w;
	for (int i = 0; i < M; ++i)
	{
		//cin >> u >> v >> w;
		scanf("%d %d %ld", &u, &v, &w);
		if (graph[u][v] == 0 || graph[v][u] == 0)
		{
			graph[u][v] = w;
			graph[v][u] = w;
		}
		else
		{
			graph[u][v] = min(w, graph[u][v]);
			graph[v][u] = min(w, graph[v][u]);
		}
	}

	int L = 0;
	int R = 1000000;
	int mid = 0;
	while (canReachT(L) == false && canReachT(R) == true && L + 1 < R)
	{
		mid = (L + R) / 2;
		if (canReachT(mid) == true)
		{
			R = mid;
		}
		else
		{
			L = mid;
		}
	}

	if (canReachT(L) == false && canReachT(R) == true && L + 1 == R)
	{
		//cout << R << endl;
		printf("%d\n", R);
	}
	else
	{
		cout << "error" << endl;
	}

}

bool canReachT(long x)
{
	deque<bool> visited(N + 5, false);
	visited[1] = true;
	return canReachTUtil(1, T, x, 0, visited); 	
}

bool canReachTUtil(int src, int dest, long x, int cnt, deque<bool>& visited)
{
	// base case
	if (dest == src && cnt <= K) return true;
	if (cnt > K) return false;

	int u = src;

	for (int v = 1; v <= N; ++v)
	{
		// for each neighbor that has not been visited && w <= x
		if (graph[u][v] != 0 && !visited[v] && graph[u][v] <= x)
		{
			visited[v] = true;
			if (canReachTUtil(v, dest, x, cnt + 1, visited)) return true;
			// backtracking
			visited[v] = false;
		}
	}
	return false;
}