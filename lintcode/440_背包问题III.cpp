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
 * 完全背包问题
 * 状态定义 dp[m]：容量 m 的背包所能存放的最大价值
 * 状态转移：遍历每一种物品 i，放入背包，并选择放入后价值的最大值
 *          dp[m] = max_i dp[m-size_i] + v[i]
 * 初始值：dp[0] = 0
 * 时间复杂度：O(m * n)
 * 空间复杂度：O(m)
 */
int backPackIII(vector<int>& A, vector<int>& V, int m) {
    if (A.empty()) return 0;
    if (m == 0) return 0;
    int n = (int)A.size();

    // dp[m]: 容量为m的背包能放的最大价值
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        // 尝试每一种物品
        int maxValue = 0;
        for (int j = 0; j < n; ++j) {
            int thisSize = A[j];
            int thisValue = V[j];
            if (thisSize <= i) {
                maxValue = max(maxValue, dp[i - thisSize] + thisValue);
            }
        }
        dp[i] = maxValue;
    }

    return dp[m];
}