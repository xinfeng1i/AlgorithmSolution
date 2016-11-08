#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// DP Solution: TLE
// Time complexity: O(n1*n2)
bool isSubsequence2(string s, string t) {
	int n1 = s.size();
	int n2 = t.size();
	if (n1 > n2) return false;
	if (n1 == n2) {
		if (s == t) return true;
		else return false;
	}
	
	// Now n1 < n2
	// dp[i][j] = s的前i个字符是否是t的前j个字符的子序列
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	for (int j = 0; j <= n2; ++j) dp[0][j] = 1; // 空串是任何串的子序列
	for (int i = 1; i <= n1; ++i) dp[i][0] = 0; // 任何非空串不是空串的子序列
	
	for (int i = 1; i <= n1; ++i) {
		for (int j = i; j <= n2; ++j) {
			if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = dp[i][j-1];
		}
	}
	return dp[n1][n2];
}

// Greedy, search the char one by one
// Time Complexity: O(n1+n2)
bool isSubsequence(string s, string t) {
	int n1 = s.size();
	int n2 = t.size();
	if (n1 > n2) return false;
	if (n1 == n2) {
		if (s == t) return true;
		else return false;
	}
	int i = 0;
	int j = 0;
	while (i < n1) {
		while (j < n2 && t[j] != s[i]) j++;
		if (j >= n2) return false; // cannot find some specific char
		i++;
		j++;
	}
	return true;
}

int main()
{
	string s = "acb";
	string t = "ahbgdc";
	cout << isSubsequence(s, t) << endl;
	return 0;
}
