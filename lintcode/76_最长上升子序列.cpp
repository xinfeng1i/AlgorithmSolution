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



/*
 * 定义: dp[i] 表示以i结尾的LIS的长度
 */
int longestIncreasingSubsequence(vector<int>& v) {
    if (v.empty()) return 0;
    int n = (int)v.size();

    vector<int> dp(n, 0);
    // base status
    dp[0] = 1;

    // recursion status
    for (int i = 1; i < n; ++i) {
        int maxLength = 1;
        for (int j = 0; j < i; ++j) {
            if (v[i] > v[j]) {
                maxLength = max(maxLength, dp[j]+1);
            }
        }
        dp[i] = maxLength;
    }

    // answer
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
    vector<int> v1 = { 4,2,4,5,3,7 };
    cout << longestIncreasingSubsequence(v1) << endl;
    return 0;
}