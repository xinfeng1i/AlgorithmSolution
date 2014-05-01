#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
const int INF = 30000;
int graph[N][N];
bool canFinish[N];
int minLength[N];

int main()
{

	//freopen("input.txt", "r", stdin);

	// init
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		graph[i][i] = 0;
		canFinish[i] = true;
		minLength[i] = INF + 5;
	}

	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int b, e, w;
	for (int i = 0;i< m; ++i)
	{
		scanf("%d %d %d", &b, &e, &w);
		graph[b][e] = w;
		graph[e][b] = w;
	}

	// shortest path between all pairs, Floyd-Washell algorithm
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	/*
	printf("graph:\n");
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	printf("graph end !\n");
	*/


	// record all the row if can finish the task
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (graph[i][j] == INF)
			{
				canFinish[i] = false;
				break;
			}
		}
	}

	/*
	printf("Can finsh\n");
	for (int i = 1; i <= n; ++i)
	{
		cout << canFinish[i] << endl;
	}
	printf("can finish end\n");
	*/

	bool flag = false;
	for (int i = 1; i <= n; ++i)
	{
		if (canFinish[i])
			flag = true;
	}

	if (!flag)
	{
		printf("0\n");
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (canFinish[i])
			{
				int rowmax = -1;
				for (int j = 1; j <= n; ++j)
				{
					rowmax = max(rowmax, graph[i][j]);
				}
				minLength[i] = rowmax;
			}
		}

		int ans_length = INF + 5;
		int ans_index = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (canFinish[i] && minLength[i] < ans_length)
			{
				ans_length = minLength[i];
				ans_index = i;
			}
		}

		printf("%d %d\n", ans_index, ans_length);

	}

	return 0;
}
