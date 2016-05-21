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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// 从naive的解出发，发现存在着【重叠子问题】，因此考虑是否能用动态规划
// 进行解决，经过初步的尝试发现，当前位置的“全1方阵”（以下简称“方阵”）的边长
// 取决于前近邻的三个位置的边长值，具体地
// 定义　dp[i][j] = 以i，j位置为方阵右下角结尾的方阵的边长
// 则 dp[i][j] = 1  if A[i-1][j-1] = 0 或者 A[i][j-1] = 0 或者 A[i-1][j] = 0
// dp[i][j] = min{A[i-1][j-1], A[i][j-1], A[i-1][j]} + 1
// 从而问题得到解决

int maximalSquare(vector<vector<char>>& A) {
    if (A.empty()) return 0;
    int m = (int)A.size();
    int n = (int)(A[0].size());
        
    int ans = 0;
        
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) { dp[0][j] = (A[0][j] - '0'); ans = max(ans, dp[0][j]); }
    for (int i = 0; i < m; ++i) { dp[i][0] = (A[i][0] - '0'); ans = max(ans, dp[i][0]); }
        
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (A[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                if (A[i-1][j-1] == '0' || A[i-1][j] == '0' || A[i][j-1] == '0') {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                }
            }
            ans = max(ans, dp[i][j]);
                
        }
    }
        
    return ans * ans;     
}