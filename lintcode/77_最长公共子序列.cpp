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


// dp[i][j]: 长度为i的A串与长度为j的B串的LCS长度
// 状态转移：
//     dp[i][j] = dp[i-1][j-1] + 1 if A[i-1]==B[j-1]
//     dp[i][j] = max(dp[i-1][j], dp[i][j-1]) otherwise
// 时间复杂度: O(m*n)
// 空间复杂度：O(m*n)
int longestCommonSubsequence(string& A, string& B) {
    if (A.empty() || B.empty()) return 0;

    int m = (int)A.size();
    int n = (int)B.size();

    vector<vector<int>> dp;
    for (int i = 0; i < m+1; ++i) {
        vector<int> temp(n+1, 0);
        dp.push_back(temp);
    }

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string A = "ABCD";
    string B = "EACB";
    cout << longestCommonSubsequence(A, B) << endl;
    return 0;
}