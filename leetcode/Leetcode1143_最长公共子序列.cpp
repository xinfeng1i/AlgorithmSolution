#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


int longestCommonSubsequence(string A, string B) {
    if (A.empty() || B.empty()) return 0;

    int m = A.size();
    int n = B.size();
    // dp[i][j]: 长度为i的A与长度为j的B的最长公共子串的长度
    // ans: dp[m][n]

    vector<vector<int>> dp;
    for (int i = 0; i <= m; ++i) {
        vector<int> temp(n + 1, 0);
        dp.push_back(temp);
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];
                dp[i][j] = max(max(a, b), c);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    string w1 = "abc";
    string w2 = "edf";

    cout << longestCommonSubsequence(s1, s2) << endl;
    cout << longestCommonSubsequence(w1, w2) << endl;

    return 0;

}