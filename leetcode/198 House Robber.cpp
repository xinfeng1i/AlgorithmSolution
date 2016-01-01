#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Dynamic problem:
// for current house, there are only two choice:
// rob it or not rob it
// if rob it, then the previous must not be robbed, so the money
// is dp[i-2] + nums[i];
// else not rob it, so the money is the money got till previous
// house, is dp[i-1]
// so dp[i] = max{dp[i-2] + nums[i], dp[i-1]}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    
    for (int j = 1; j < n; ++j) {
        if (j - 2 >= 0) {
            dp[j] = max(dp[j-2] + a[j], dp[j-1]);
        } else {
            dp[j] = max(dp[j-1], a[j]);
        }
    }
    
    int maxVal = 0;
    for (int j = 0; j < n; ++j) {
        if (dp[j] > maxVal) maxVal = dp[j];
    }
    return maxVal;
}