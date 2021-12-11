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


/** 
 * 经典背包问题：
 * dp[i][j]: 给定i个物品，j大小空间所能存放的最大价值
 * 状态转移：
 * dp[i][j] = dp[i-1][j-thisSize] + V[i]  select the ith item
 *          = dp[i-1][j]  otherwise
 * Note: if thisSize > j, then only the second equation can keep.
 * 时间复杂度：O(n*m)
 * 空间复杂度：O(n*m)
 */
int backPackII(int m, vector<int>& A, vector<int>& V) {
    if (A.empty()) return 0;
    assert(A.size() == V.size());
    int n = (int)A.size();

    // init
    vector<vector<int>> dp;
    for (int i = 0; i <= n; ++i) {
        vector<int> temp(m + 1, 0);
        dp.push_back(temp);
    }
    // 背包容量为0时，最大价值均为0
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    // 物品个数为0时，最大价值为0
    for (int j = 0; j <= m; ++j) dp[0][j] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int thisValue = V[i - 1];
            int thisSize = A[i - 1];
            if (thisSize > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                int temp1 = dp[i - 1][j - thisSize] + thisValue;
                int temp2 = dp[i - 1][j];
                dp[i][j] = max(temp1, temp2);
            }
        }
    }

    return dp[n][m];
}

