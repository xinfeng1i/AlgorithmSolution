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


/** 
 * 编辑距离：经典DP问题
 * dp[i][j]:前缀长度为i的A与长度为j的B的最小编辑距离
 * 状态转移：如果最后一个位置相等，则退化成一个更小的问题，否则交错小问题
 * 时间复杂度：O(m*n)
 * 空间复杂度：O(m*n)
 */
int minDistance(string& A, string& B) {
    // 
    if (A.empty() && B.empty()) return 0;
    if (A.empty() && !B.empty()) return B.size();
    if (!A.empty() && B.empty()) return A.size();

    int m = (int)A.size();
    int n = (int)B.size();
    vector<vector<int>> dp;
    for (int i = 0; i <= m; ++i) {
        vector<int> temp(n + 1, 0);
        dp.push_back(temp);
    }

    // init status
    for (int j = 0; j <= n; ++j) dp[0][j] = j;
    for (int i = 0; i <= m; ++i) dp[i][0] = i;

    // recursion from bottom to up
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                int temp1 = dp[i - 1][j - 1] + 1;
                int temp2 = dp[i - 1][j] + 1;
                int temp3 = dp[i][j - 1] + 1;
                dp[i][j] = min(min(temp1, temp2), temp3);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string A = "horse";
    string B = "ros";
    cout << minDistance(A, B) << endl;
    return 0;
}