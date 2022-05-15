#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

// dp[n][sum/2] 表示前n个元素中挑选部分元素其和可以等于sum/2
// ans: dp[n][sum/2]
// Time: O(n*sum/2)
// Space: O(n*sum/2)
bool canPartition(vector<int>& nums) {
    int n = (int) nums.size();
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    if (sum % 2 == 1) return false;
    
    sum = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (j < nums[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                int temp1 = dp[i-1][j-nums[i-1]];
                int temp2 = dp[i-1][j];
                if (temp1 == 1 || temp2 == 1) {
                    dp[i][j] = 1;
                }
            }
        }
    }
    
    if (dp[n][sum] == 1) return true;
    else return false;
}


#if 0
int main() {
    vector<int> v1 = { 1, 5, 11, 5 };
    cout << canPartition(v1) << endl;
    
    return 0;
}
#endif // 0
