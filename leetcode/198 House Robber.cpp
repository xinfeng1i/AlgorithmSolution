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

// 动态规划：
// 定义 dp[n] = 到第n个房子能抢到的最大财富同时不引起警报
// 最后一个房子有两种选择：
// 1. 抢；在这种情况下，前一个房子必然不能被抢, 总财富=dp[n-2] + A[n]
// 2. 不抢；在这种情况下，实际上就是抢n-1房子的财富，即dp[n-1]
// 综上: dp[n] = max(dp[n-1], dp[n-2]+A[n])
int rob(vector<int>& nums) {
	int n = (int)nums.size();
	if (n == 0) return 0;
	
	vector<int> dp(nums.begin(), nums.end());
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			dp[i] = nums[i];
		} else if (i == 1) {
			dp[i] = max(nums[0], nums[1]);
		} else if (i >= 2) {
			dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
		}
	}

	return dp[n-1];
}