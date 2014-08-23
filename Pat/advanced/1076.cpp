#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

typedef vector<vector<int> > MyMatrix;


/* 
 * dfs 2 sample not work
 * for example
 *       1
 *      / \
 *     0 --2 --> 2
 * will not visit the last node 2
 */
void dfs(const MyMatrix& adjMatrix, deque<bool>& visited, int src, int curLevel, int nLevel)
{
	if (curLevel > nLevel) return;
	visited[src] = true;
	for (int j = 0; j < adjMatrix[src].size(); ++j)
	{
		if (adjMatrix[src][j] == 1 && !visited[j])
		{
			dfs(adjMatrix, visited, j, curLevel+1, nLevel);
		}
	}
}

void bfs(const MyMatrix& adjMatrix, deque<bool>& visited, int src, int curLevel, int nLevel)
{
	queue<int> q;
	visited[src] = true;
	q.push(src);
	vector<int> level(visited.size(), -1);
	level[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (level[u] >= nLevel) continue;
		for (int v = 0; v < adjMatrix[u].size(); ++v)
		{
			if (adjMatrix[u][v] == 1 && !visited[v])
			{
				visited[v] = true;
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int N, L;
	scanf("%d %d", &N, &L);
	vector<vector<int> > adjMatrix(N, vector<int>(N, -1));

	int m = 0; int tmp = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &tmp);
			adjMatrix[tmp-1][i] = 1;
		}
	}

	int K = 0;
	scanf("%d", &K);
	vector<int> query(K, 0);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &query[i]);
	}

	for (int i = 0; i < K; ++i)
	{
		int x = query[i] - 1;
		//cout << "x:" << x << endl;
		deque<bool> visited(N, false);
		bfs(adjMatrix, visited, x, 0, L);
		int cnt = 0;
		for (int j = 0; j < N; ++j)
		{
			if (visited[j] == true) cnt++;
		}
		cout << cnt - 1 << endl;
	}

	return 0;
}
