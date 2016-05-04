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
// 定义dp[i] = 以i结尾的最大子数组和
//
// Claim 1:
// 那么以i+1结尾的最大子数组和dp[i+1]必然是dp[i]+a[i+1]和a[i+1]的较大者
// 证明如下：
// 如果i+1计结尾的最大子数组比dp[i]更长，如图*表示，则多余的部分只有3种可能：
// 1. 多余的部分为正，那么此时dp[i]也可以扩充该多余部分，与dp[i]是最优解矛盾；
// 2. 多余的部分为负，此时可以通过不包含该多余部分得到更大的dp[i+1]
// 3. 多余的部分为0，此时不包括该多余部分同样可以得到最大的dp[i+1]
// [] [] [] [] [] [] [i] [i+1] []
//          +  +  +  + 
//    *  *  *  *  *  *   *
//             ^  ^  ^   ^
// Claim 2:
// 同理，dp[i+1]包括部分也不可能短于dp[i], 如图^所示
// 1. 如果少的部分为正，则包括该部分可以得到更大的dp[i+1]
// 2. 如果少的部分为负，则dp[i]可以排除该部分后得到更大的dp[i],与dp[i]是最优矛盾
// 3. 如果少的部分为0，则dp[i+1]包含该部分不影响结果
//
// 通过Claim1 和 Claim2可以得知
// dp[i+1]包含的长度将刚好等于dp[i]包含的长度+1
// 于是取dp[i]+nums[i+1]和nums[i+1]的最大值即可得到最优解
int maxSubArray(vector<int>& nums) {
	int n = (int)(nums.size());
	vector<int> dp(nums.begin(), nums.end());
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1]+nums[i], nums[i]);
	}

	int ans = nums[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, dp[i]);
	}

	return ans;
}

#if 0
int main()
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> v(a, a + 9);
	cout << maxSubArray(v) << endl;
	return 0;
}
#endif //0