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

// dp[i][j]����ʾ�Գ���i�ͳ���j��β��LCS�ĳ���
// ״̬ת�ƣ�dp[i][j] = dp[i-1][j-1]+1 if A[i-1]==B[j-1] 
//                   = 0 otherwise
// ʱ�临�Ӷȣ�O(m*n)
// �ռ临�Ӷȣ�O(m*n)
int longestCommonSubstring(string& A, string& B) {
    if (A.empty() || B.empty()) return 0;

    
    int m = (int)A.size();
    int n = (int)B.size();

    // init status
    vector<vector<int>> dp;
    for (int i = 0; i <= m; ++i) {
        vector<int> temp(n + 1, 0);
        dp.push_back(temp);
    }

    for (int j = 0; j <= n; ++j) dp[0][j] = 0;
    for (int i = 0; i <= m; ++i) dp[i][0] = 0;

    // recursion
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}