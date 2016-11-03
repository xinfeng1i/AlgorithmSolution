#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int minDistance(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	
	// dp[i][j]表示s1的前i个字符构成的子串和s2的前j个字符
	// 构成的子串的编辑距离
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	// 如果第一个字符串是空串，则必须插入整个第二字串,因此编辑距离
	// 是第二字符串的长度；反之如果第二个字符串是空串，则第一个字符串
    // 必须删除所有的字符才能变成第二个字符串
	for (int j = 0; j <= n2; ++j) {
		dp[0][j] = j;
	}
	for (int i = 0; i <= n1; ++i) {
		dp[i][0] = i;
	}
	dp[0][0] = 0;
	
	// 在s1和s2都新插入一个字符c1, c2后，根据其对齐方式有三种情况：
	// 1. c1和c2对齐，此时如果c1==c2其编辑距离为dp[i-1][j-1], 否则
	//    需要替换c1为c2，距离+1, replce_cost
	// 2. c1和s2的前j-1字符对齐, 则此时需要在s1种插入一个新的c2, insert_cost
	// 3. c2和s1的前i-1字符对齐，此时需要删除s1新插入的c1字符, delete_cost
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			int replace_cost = dp[i-1][j-1] + (s1[i-1]==s2[j-1]?0:1);
			int insert_cost = dp[i][j-1] + 1;
			int delete_cost = dp[i-1][j] + 1;
			dp[i][j] = min(replace_cost, min(insert_cost, delete_cost));
		}
	}
	return dp[n1][n2];
}

int main()
{
	string w1 = "appe";
	string w2 = "apple";
	cout << minDistance(w1, w2) << endl;
	return 0;
}
