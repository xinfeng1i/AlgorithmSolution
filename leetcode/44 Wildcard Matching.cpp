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
using namespace std;

// 定义dp[i][j]表示s[0...i]和p[0...j]是否匹配
// 1. dp[i][j] = dp[i-1][j-1]  if p[j] != '*'
// 2. dp[i][j] = dp[i-1][j] || dp[i][j-1] if p[j] == '*' 
// ^^^^^^^^^^
// &&&&&&&*
// 2表示如果最后一个字符是*，则有两种情况，一种情况是*不匹配任何字符
// 则问题转化为dp[i][j-1]是否匹配；另一种情况是*至少匹配一个字符，这种情况
// 下，dp[m][j-1] (0<=m<j)如果匹配，则必然dp[i][j]也匹配
bool isMatch(string s, string p) {

	int n1 = (int)s.size();
	int n2 = (int)p.size();
	// dp[i][j]表示长度为i的s和长度为j的p是否匹配
	vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n1; ++i) dp[i][0] = false;
	for (int j = 1; j <= n2; ++j) {
		if (p[j-1] == '*') dp[0][j] = true;
		else break;
	}

	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (p[j-1] != '*') {
				dp[i][j] = (p[j-1] == '?' || p[j-1] == s[i-1]) && dp[i-1][j-1];
			} else if (p[j-1] == '*') {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}

	return dp[n1][n2];
}