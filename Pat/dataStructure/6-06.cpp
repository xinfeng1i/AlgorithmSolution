#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 105;
const int INF = 300000;
bool visited[N];
bool recStack[N];
int graph[N][N];

bool hasCycleFrom(int v, bool visited[], bool recStack[], int n)
{
	if (visited[v] == false)
	{
		visited[v] = true;		
		recStack[v] = true;		// push into stack

		// recursion for all its neighbors
		for (int j = 1; j <= n; ++j)
		{
			if (graph[v][j] != INF)
			{
				if (!visited[j] && hasCycleFrom(j, visited, recStack, n))
					return true;
				else if (recStack[j])
					return true;
			}
		}
	}

	recStack[v] = false;	// pop from the stack
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);

	// init
	for (int i = 0; i < N; ++i)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = INF;
		}
	}


	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		int k, tmp;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &tmp);
			graph[tmp][i] = 1;
		}
	}


	bool flag = false;
	for (int i = 1; i <= n; ++i)
	{
		if (hasCycleFrom(i, visited, recStack, n))
			flag = true;
	}

	if (!flag) cout << 1 << endl;
	else cout << 0 << endl;

	return 0;
}
