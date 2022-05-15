#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


// dp[i][j]: 使用前i种物品凑成j的种类数
// ans: dp[n][amount]
//
// 若不使用第i种coin：dp[i][j] = dp[i-1][j]
// 若使用第i种coin，使用几个： dp[i][j] = sum dp[i-1][j-k*coin_i]
//
// dp[i][0] = 1
// dp[0][j] = 0
//
// Time: O(n * amount)
// Space: O(n * amount), can be optimized to be O(amount)
int change(int amount, vector<int>& coins) {
    int n = (int) coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (coins[i-1] > j) {
                // 只能不使用第i种coin
                dp[i][j] = dp[i-1][j];
            } else {
                int k = floor(j / coins[i-1]);
                int cnt = 0;
                for (int q = 0; q <= k; ++q) {
                    cnt += dp[i-1][j - q * coins[i-1]];
                }
                dp[i][j] = cnt;
            }
        }
    }
    
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= amount; ++j) {
//            cout << " " << dp[i][j];
//        }
//        cout << endl;
//    }
    
    return dp[n][amount];
}


int main() {
    vector<int> v1 = { 1, 2, 5 };
    int n1 = 5;
    cout << "case 1:" << endl;
    cout << change(n1, v1) << endl;
    
    vector<int> v2 = { 2 };
    int n2 = 3;
    cout << "case 2:" << endl;
    cout << change(n2, v2) << endl;
    
    vector<int> v3 = { 10 };
    int n3 = 10;
    cout << "case 3:" << endl;
    cout << change(n3, v3) << endl;
    
    return 0;
}
