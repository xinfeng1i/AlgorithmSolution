#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
* @param obstacleGrid: A list of lists of integers
* @return: An integer
*/
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    const size_t m = obstacleGrid.size();
    assert(m >= 1);
    const size_t n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (size_t j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
        dp[0][j] = 1;
    }
    for (size_t i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
        dp[i][0] = 1;
    }
    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

#if 0
int main() {
    vector<vector<int>> v(3, vector<int>(3, 0));
    v[1][1] = 1;
    cout << uniquePathsWithObstacles(v) << endl;
    return 0;
}
#endif //0