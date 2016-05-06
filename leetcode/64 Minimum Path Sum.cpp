#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// 经典动态规划问题
int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;

	int m = (int)grid.size();
	int n = (int)grid[0].size();

	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	for (int j = 1; j < n; ++j) {
		dp[0][j] = dp[0][j-1] + grid[0][j];
	}
	for (int i = 1; i < m; ++i) {
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i-1][j] + grid[i][j]);
		}
	}

	return dp[m-1][n-1];
}

int main()
{
	cout << "" << endl;
	return 0;
}