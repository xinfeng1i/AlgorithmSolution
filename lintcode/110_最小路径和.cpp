#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


/*
 * 状态定义：
 *    dp[i][j] 表示从start开始到(i,j)坐标的路径最小和
 * 转移:
 *    dp[i][j] = dp[i-1][j] + grid[i][j]
                 dp[i][j-1] + grad[i][j] 两者取最小值
 * 初始值：
 *    第一行和第一列累加
 */
int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    if (n == 0) return 0;

    // init
    vector<vector<int>> dp;
    for (int i = 0; i < m; ++i) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }

    // init status
    dp[0][0] = grid[0][0];
    for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j - 1] + grid[0][j];
    for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int temp1 = dp[i - 1][j] + grid[i][j];
            int temp2 = dp[i][j - 1] + grid[i][j];
            dp[i][j] = min(temp1, temp2);
        }
    }
    
    return dp[m - 1][n - 1];
}


#if 0
int main() {
    vector<vector<int>> grid;
    vector<int> v1 = { 1, 3, 1 };
    vector<int> v2 = { 1, 5, 1 };
    vector<int> v3 = { 4, 2, 1 };
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);

    cout << minPathSum(grid) << endl;

    return 0;
}
#endif // 0