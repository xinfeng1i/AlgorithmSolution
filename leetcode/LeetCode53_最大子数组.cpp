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
 * 状态dp[i]: 以i位置结尾的最大子数组的和
 * 状态转移：dp[i] = max(dp[i-1] + A[i], A[i])
 * 结果：遍历所有的dp[i]找到最大值即可
 *
 * 时间复杂度：O(n)
 * 空间复杂度: O(n)
 */
int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    int n = (int)nums.size();
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int answer = dp[0];
    for (int i = 1; i < n; ++i) {
        answer = max(answer, dp[i]);
    }
    return answer;
}


int main() {
    vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(v) << endl;
    return 0;
}