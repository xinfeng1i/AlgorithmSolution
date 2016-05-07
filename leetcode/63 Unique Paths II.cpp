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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.empty()) return 0;

	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));

	if (obstacleGrid[0][0] == 1) return 0;

	dp[0][0] = 1;
	int j = 1;
	while (j < n && obstacleGrid[0][j] == 0) { dp[0][j] = 1; j++; }
	while (j < n) { dp[0][j] = 0; j++; }

	int i = 1;
	while (i < m && obstacleGrid[i][0] == 0) { dp[i][0] = 1; i++; }
	while (i < m) { dp[i][0] = 0; i++; }

	for (i = 1; i < m; ++i) {
		for (j = 1; j < n; ++j) {
			if (obstacleGrid[i][j] == 1) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}

	return dp[m-1][n-1];

}