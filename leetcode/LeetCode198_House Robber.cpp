//
//  LeetCode198_House Robber.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/12/8.
//
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
 * Easy DP
 * Time: O(n)
 * Space: O(n), can be optimized to O(1)
 */
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return nums[0] >= nums[1] ? nums[0] : nums[1];
    
    int n = (int) nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[0] >= nums[1] ? nums[0] : nums[1];
    for (int i = 2; i < n; ++i) {
        int temp1 = dp[i-2] + nums[i];
        int temp2 = dp[i-1];
        dp[i] = max(temp1, temp2);
    }
    return dp[n-1];
}

#if 0
int main() {
    vector<int> v1 = {1, 2, 3, 1};
    cout << rob(v1) << endl;
    
    vector<int> v2 = {2, 7, 9, 3, 1};
    cout << rob(v2) << endl;
    
    return 0;
}
#endif // 0
