#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

// dp[i][j]: 用前i个物品凑成j所需要的最少物品个数，则目标为求 dp[n][amount]
// base case:
//   dp[0][j] = -1
//   dp[i][0] = 0
// state tranfer:
//   not using ith: dp[i-1][j]
//   using ith:     dp[i][j-coins_i] + 1
//
// Time: O(n * amount)
// space: O(n * amount), can be further optimized to O(amount)
int coinChange(vector<int>& coins, int amount) {
    int n = int (coins.size());
    
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    for (int j = 1; j <= amount; ++j) dp[0][j] = -1;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (j < coins[i - 1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                int totCnt = INT_MAX;
                
                // not using ith coin
                int cnt1 = dp[i-1][j];
                if (cnt1 != -1) {
                    totCnt = min(totCnt, cnt1);
                }
                // using ith coin
                int prevCnt = dp[i][j-coins[i-1]];
                if (prevCnt != -1) {
                    totCnt = min(totCnt, prevCnt + 1);
                }
                
                dp[i][j] = totCnt == INT_MAX ? -1: totCnt;
            }
        }
    }
    
    return dp[n][amount];
}


int main() {
    vector<int> v1 = { 1, 2, 5 };
    int n1 = 11;
    cout << "case 1: " << endl;
    cout << coinChange(v1, n1) << endl;
    
    
    vector<int> v2 = { 2 };
    int n2 = 3;
    cout << "case 2: " << endl;
    cout << coinChange(v2, n2) << endl;
    
    vector<int> v3 = { 1 };
    int n3 = 0;
    cout << "case 3: " << endl;
    cout << coinChange(v3, n3) << endl;
    
    return 0;
}
