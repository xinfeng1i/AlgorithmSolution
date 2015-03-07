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

// Define: cnt[i][j] = the number of unique paths from(0,0) to (i,j)
// Recursion:
// cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
// Init:
// cnt[1][j] = 1;
// cnt[i][1] = 1;
// Complexity: O(mn) space & time overhead
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	vector<vector<int> > cnt(m, vector<int>(n, 0));
	// init: the first row left the first 1 is all 1
	//                     right the first 1 is all 0
	int col = 0;
	while (col < n && obstacleGrid[0][col] == 0)
	{
		cnt[0][col] = 1;
		col++;
	}
	while (col < n)
	{
		cnt[0][col] = 0;
		col++;
	}
	// init the first col
	int row = 0;
	while (row < m && obstacleGrid[row][0] == 0) 
	{
		cnt[row][0] = 1;
		row++;
	}
	while (row < m)
	{
		cnt[row][0] = 0;
		row++;
	}

	// bottom to up
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[i][j] == 1) cnt[i][j] = 0;
			else cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
		}
	}

	return cnt[m-1][n-1];

}

int main()
{
	vector<vector<int> > grid(3, vector<int>(3, 0));
	grid[1][1] = 1;
	int ans = uniquePathsWithObstacles(grid);
	cout << ans << endl;
	return 0;
}
