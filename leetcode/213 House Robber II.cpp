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

// 仍然是动态规划
// 对于第一个房子有两种选择
// 1. 抢，则第2和最后一个房子必然不能被抢，所以需要计算从第三个房子到第倒数
//    第二个房子的抢劫总财富
// 2. 不抢，则计算第1到最后一个房子的总财富
// 这样两个子问题可以转化为 ROB1 的动态规划问题
// 最后比较1、2两种情况取最大值即可
int rob(vector<int>& nums) {
	int n = (int)nums.size();
	if (n == 0) return 0;
	if (n == 1) return nums[0];
	if (n == 2) return max(nums[0], nums[1]);

	// 1. 抢第一个房子
	vector<int> first_dp(n, 0);
	for (int i = 2; i <= n-2; ++i) {
		if (i == 2) first_dp[i] = nums[i];
		else if (i == 3) first_dp[i] = max(nums[i], nums[i-1]);
		else first_dp[i] = max(first_dp[i-1], first_dp[i-2]+nums[i]);
	}

	int ans1 = first_dp[n-2] + nums[0];
	
	// 2. 不抢第一个房子
	vector<int> no_first_dp(n, 0);
	for (int i = 1; i < n; ++i) {
		if (i == 1) no_first_dp[i] = nums[i];
		else if (i == 2) no_first_dp[i] = max(nums[i], nums[i-1]);
		else no_first_dp[i] = max(no_first_dp[i-1], no_first_dp[i-2]+nums[i]);
	}
	int ans2 = no_first_dp[n-1];

	return max(ans1, ans2);
}

int main()
{
	int a[] = {1, 3, 1};
	vector<int> v(a, a+3);
	cout << rob(v) << endl;
	return 0;
}