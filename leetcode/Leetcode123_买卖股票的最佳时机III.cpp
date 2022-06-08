#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


/**
 * 状态定义：dp[i][k][0] 表示到第i天为止在最多交易k次的情况下且手中没有股票的情况下，获取的最大利润
 *          dp[i][k][1] 表示到第i天为止在最多交易k次的情况下且手中持有股票的情况下，获取的最大利润
 * 状态转移：dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
 *          dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
 * 状态初值：dp[0][k][0] = 0
 *          dp[0][k][1] = INT_MIN
 *
 */
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    int k = 2;
    vector<vector<int>> dp0(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> dp1(n + 1, vector<int>(k + 1, 0));
    for (int j = 0; j <= k; ++j) dp1[0][j] = INT_MIN;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j] + prices[i - 1]);
            dp1[i][j] = max(dp1[i - 1][j], dp0[i - 1][j - 1] - prices[i - 1]);
        }
    }

    return dp0[n][k];
}


int main() {
    vector<int> v1 = { 3,3,5,0,0,3,1,4 };
    vector<int> v2 = { 1,2,3,4,5 };
    vector<int> v3 = { 7,6,4,3,1 };

    cout << maxProfit(v1) << endl;
    cout << maxProfit(v2) << endl;
    cout << maxProfit(v3) << endl;

    return 0;
}