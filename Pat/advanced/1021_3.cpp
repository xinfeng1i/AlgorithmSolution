#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

const int INF = 1000000;

void dfs(const vector<vector<int> >& matrix, deque<bool>& visited, int src)
{
	visited[src] = true;
	for (int j = 0; j < matrix[src].size(); ++j)
	{
		if (matrix[src][j] == 1 && !visited[j])
		{
			dfs(matrix, visited, j);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int> > matrix(n, vector<int>(n, INF));
	int s, e;
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d %d", &s, &e);
		matrix[s-1][e-1] = 1;
		matrix[e-1][s-1] = 1;
	}

	deque<bool> visited(n, false);
	
	// compute components
	int cmpts = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			dfs(matrix, visited, i);
			cmpts++;
		}
	}
	
	if (cmpts >= 2)
	{
		printf("Error: %d components\n", cmpts);
		return 0;
	}
	
	// compute longest distance
	// init
	for (int i = 0; i < n; ++i) matrix[i][i] = 0;
	// floyd-warshall
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][k] != INF && matrix[k][j] != INF &&
					matrix[i][k] + matrix[k][j] < matrix[i][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
	
	// get longest dist
	int maxDist = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] != INF && matrix[i][j] > maxDist)
			{
				maxDist = matrix[i][j];
			}
		}
	}

	set<int> ans;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == maxDist)
			{
				ans.insert(i);
				ans.insert(j);
			}
		}
	}

	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		cout << *it + 1 << endl;
	}
	return 0;
}
