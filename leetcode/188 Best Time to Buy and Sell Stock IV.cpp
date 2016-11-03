#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxProfitNoLimit(vector<int>& prices) {
	int n = prices.size();
	if (n <= 1) return 0;
	int ans = 0;
	for (int j = 1; j < n; ++j) {
		if (prices[j] > prices[j-1]) {
			ans += prices[j] - prices[j-1];
		}
	}
	return ans;
}

int maxProfit(int k, vector<int>& prices) {
	int n = prices.size();
	// dp[t][j]表示对长度为j的数组用不超过t次的交易
	// 能获取的最大利润，则结果就是求dp[2][n]
	if (n <= 1) return 0;
	
	// 优化时间复杂度
	if (k >= n / 2) return maxProfitNoLimit(prices);

	vector<vector<int>> dp(k+1, vector<int>(n+1, 0));
	// 0 次交易不能获得任何利润
	for (int j = 0; j <= n; ++j) dp[0][j] = 0;
	// 长度为0的数组不能获得任何利润
	for (int i = 0; i <= k; ++i) dp[i][0] = 0;

	// 最后一个元素prices[j]有两种选择：
	// 1. 最后一次交易包含prices[j]
	// 2. t次交易均不包含prices[j],则dp[t][j] = dp[t][j-1]
	// dp[t][j] = max(dp[t][j-1], max(prices[j-1]-prices[jj-1]+dp[t-1][jj-1])
	//          = max(dp[t][j-1], prices[j-1]+max(dp[t-1][jj-1]-prices[jj-1]))
	// jj in [1, j)
	for (int t = 1; t <= k; ++t) {
		dp[t][1] = 0; // 1个元素t次交易利润为0
		int prev_temp_max = dp[t-1][0] - prices[0];
		for (int j = 2; j <= n; ++j) {
			dp[t][j] = max(dp[t][j-1], prices[j-1]+prev_temp_max);
			prev_temp_max = max(prev_temp_max, dp[t-1][j-1]-prices[j-1]);
		}
	}
	return dp[k][n];
}
