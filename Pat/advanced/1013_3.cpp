#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 1
// DFS
// undirected graph connected components

const int MAXN = 1010;
int graph[MAXN][MAXN];
int n = 0;
int m = 0;
int k = 0;

void DFS(int u, vector<bool>& visited) {
	visited[u] = true;
	for (int i = 1; i <= n; ++i) {
		if (graph[u][i] != 0 && !visited[i]) {
			DFS(i, visited);
		}
	}
}

int nRepairedWay(int u) {
	vector<int> temp(graph[u], graph[u]+MAXN);
	for (int j = 1; j <= n; ++j) {
		graph[u][j] = 0;
		graph[j][u] = 0;
	}

	int cnt = 0;
	vector<bool> visited(n+1, false);
	for (int i = 1; i <= n; ++i) {
		if (i != u && !visited[i]) {
			DFS(i, visited);
			cnt++;
		}
	}

	for (int j = 1; j <= n; ++j) {
		graph[u][j] = temp[j];
		graph[j][u] = temp[j];
	}

	return cnt-1;
}


int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	int u = 0, v = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	int city = 0;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &city);
		int ans = nRepairedWay(city);
		printf("%d\n", ans);
	}

	return 0;
}
#endif //0