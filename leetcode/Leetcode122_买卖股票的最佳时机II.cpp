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
 * 状态定义：dp[i][1] 到第i天为止且手中持有股票的情况下，获取的最大利润
 *          dp[i][0] 到第i天为止且手中没有股票的情况下，获取的最大利润
 * 状态转移：dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
 *          dp[i][1] = max(dp[i-1][0], dp[i-1][0]-prices[i])
 * 初始状态：dp[0][0] = 0
 *          dp[0][1] = INT_MIN
 */
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    vector<int> dp0(n + 1, 0);
    vector<int> dp1(n + 1, 0);

    dp0[0] = 0;
    dp1[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i - 1]);
        dp1[i] = max(dp1[i - 1], dp0[i - 1] - prices[i - 1]);
    }

    return dp0[n];
}


int main() {
    vector<int> v1 = { 7,1,5,3,6,4 };
    cout << maxProfit(v1) << endl;

    vector<int> v2 = { 1,2,3,4,5 };
    cout << maxProfit(v2) << endl;

    vector<int> v3 = { 7,6,4,3,1 };
    cout << maxProfit(v3) << endl;

    return 0;
}