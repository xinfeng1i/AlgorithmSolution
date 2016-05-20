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

int longestCommonSubstring(string &A, string &B) {
    // emtpy string with other string generate a centain empty sub-string
    if (A.empty() || B.empty()) return 0;
    int n1 = static_cast<int>(A.size());
    int n2 = static_cast<int>(B.size());
    vector<vector<int> > dp(n1, vector<int>(n2, 0));
    for (int j = 0; j < n2; ++j) dp[0][j] = (A[0] == B[j] ? 1 : 0);
    for (int i = 0; i < n1; ++i) dp[i][0] = (A[i] == B[0] ? 1 : 0);
        
    for (int i = 1; i < n1; ++i) {
        for (int j = 1; j < n2; ++j) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
        
    int ans = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
        
    return ans;
        
}