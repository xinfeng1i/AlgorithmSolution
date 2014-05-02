#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
bool visited[N];
int indegree[N];
int graph[N][N];

int main()
{
	freopen("input.txt", "r", stdin);

	// init
	for (int i = 0; i < N; ++i)
	{
		visited[i] = false;
		indegree[i] = 0;
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = 0;
		}
	}

	// input
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int k, tmp;
		scanf("%d", &k);
		indegree[i] = k;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &tmp);
			graph[tmp][i] = 1;
		}
	}

	// topological sort
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (/*!visited[i] && */indegree[i] == 0)
		{
			//visited[i] = true;
			q.push(i);
		}
	}

	int nTopologyNode = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		nTopologyNode++;

		for (int i = 1; i <= n; ++i)
		{
			if (graph[node][i] == 1)
			{
				indegree[i]--;
				if (indegree[i] == 0)
				{
					//visited[i] = true;
					q.push(i);
				}
			}
		}
	}

	if (nTopologyNode == n) printf("1\n");
	else printf("0\n");

	return 0;

}
