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
using namespace std;

const int INF = 300000;
int tot = INF;

int CountOnes(vector<vector<int>>& grid)
{
	int R = grid.size();
	int C = grid[0].size();
	int cnt = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (grid[i][j] == 1) cnt++;
		}
	}
	return cnt;
}

int CountUnhappiness(vector<vector<int>>& grid)
{
	int R = grid.size();
	int C = grid[0].size();
	int cnt = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (grid[i][j] == 1 && j + 1 < C && grid[i][j+1] == 1)
			{
				cnt += 1;
			}
			if (grid[i][j] == 1 && i + 1 < R && grid[i+1][j] == 1)
			{
				cnt += 1;
			}
		}
	}
	return cnt; 
}

void DFS(vector<vector<int>>& grid, int cur, int N)
{
	int R = grid.size();
	int C = grid[0].size();
	if (cur >= R * C) return;

	int r = cur / C;
	int c = cur % C;
	grid[r][c] = 1;
	DFS(grid, cur + 1, N);
	if (CountOnes(grid) == N)
	{
		tot = min(tot, CountUnhappiness(grid));
	}

	grid[r][c] = 0;
	DFS(grid, cur + 1, N);
	if (CountOnes(grid) == N)
	{
		tot = min(tot, CountUnhappiness(grid));
	}
}

void solve()
{
	int R, C, N;
	cin >> R >> C >> N;

	if (N == R * C)
	{
		cout << 2 * R * C - R - C << endl;
		return;
	}
	if (0 == N)
	{
		cout << 0 << endl;
		return;
	}

	vector<vector<int>> grid(R, vector<int>(C, -1));
	DFS(grid, 0, N);
	cout << tot << endl;
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		tot = INF;
		cout << "Case #" << nCase << ": ";
		solve();
	}
	return 0;
}