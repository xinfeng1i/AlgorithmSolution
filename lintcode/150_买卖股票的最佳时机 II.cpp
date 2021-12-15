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
 * 使用贪心算法居然可以得到正确答案，参考别人的答案，相对比较难理解
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 注意：
 * 这种方法也能正确处理 [1, 2, 5] 最大例如第一买，最后一天卖，利润=5-1=4
 * 从数值上也等于(2-1) + (5-2) = 4
 * 但是计算的过程不等于交易的过程，以这个为例子，计算了两次但是实际交易让然是
 * 第一天买入，最后一天卖出。
 */
int maxProfitII_Method1(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int ans = 0;
    int n = (int)prices.size();
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}

/*
 * 使用区间型动态规划，枚举区间中点，自己独立的解法，复杂度太高会造成超时
 * 时间复杂度：O(n^3)
 * 空间复杂度：O(n^2)
 */
int maxProfitII_Method2(vector<int>& prices) {
    // dp[i][j]: 在区间[i, j] 进行买卖所能得到的最大利润

    if (prices.size() <= 1) return 0;
    int n = (int)prices.size();
    vector<vector<int>> dp;
    for (int i = 0; i < n; ++i) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i + 1] > prices[i]) {
            dp[i][i + 1] = prices[i + 1] - prices[i];
        }
        else {
            dp[i][i + 1] = 0;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // 枚举每一个区间的中间点
            int maxValue = 0;
            for (int k = i; k < j; ++k) {
                maxValue = max(maxValue, dp[i][k] + dp[k + 1][j]);
            }
            // 或者整个区间取得最大值
            int temp = prices[j] > prices[i] ? prices[j] - prices[i] : 0;
            maxValue = max(maxValue, temp);
            dp[i][j] = maxValue;
        }
    }
    return dp[0][n - 1];
}


/*
 * 解法3：标准动态规划解法：非常巧妙，需要多反思
 *
 * 定义状态：
 *    dp0[i]表示在第i天结束交易后持有该股票的状态下，获得的最大收益
 *    dp1[i]表示在第i天结束交易后不持有该股票的状态下，所能获得的最大收益
 * 状态转移：
 *    dp0[i] = dp1[i-1]-prices[i]  当天买入
 *           = dp0[i-1]            前一天已经持有
 *    dp1[i] = dp0[i-1]+prices[i]  当天卖出
 *             dp1[i-1]
 * 初始状态:
 *    dp0[i] = -prices[i]
 *    dp1[i] = 0
 * 结果状态：
 *    answer = max(dp0[n-1], dp1[n-1])
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
int maxProfitII_Method3(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    vector<int> dp0(n, 0);
    vector<int> dp1(n, 0);

    dp0[0] = -prices[0];
    dp1[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp0[i] = max(dp1[i - 1] - prices[i], dp0[i - 1]);
        dp1[i] = max(dp0[i - 1] + prices[i], dp1[i - 1]);
    }

    int temp = max(dp0[n - 1], dp1[n - 1]);
    return temp >= 0 ? temp : 0;
}


#if 0
int main() {
    vector<int> v = { 4, 3, 2, 1 };
    cout << maxProfitII_Method3(v) << endl;
    return 0;
}
#endif// 