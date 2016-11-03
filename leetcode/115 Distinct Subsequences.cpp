#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int numDistinct(string S, string T) {
	int n1 = T.size();
	int n2 = S.size();
	
	// dp[i][j]表示T的前i个字符构成的字符串，在S中
	// 的前j个字符构成的字符串中作为子序列出现的次数
	// 因此我们的目标就是求 dp[n1][n2]
	vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
	
	// T为空串时，在S中出现的次数为1次，因为没有别的删除
	// 方法，只能将S中的所有字符都删除
	for (int j = 0; j <= n2; ++j) {
		dp[0][j] = 1;
	}
	
	// S为空串时，对于T的任何非空子串，均不可能包含其子序列
	for (int i = 1; i <= n1; ++i) {
		dp[i][0] = 0;
	}
	
	// 对于T的第i个字符和S的第j个字符，如果T[i]==S[j],那么有两种可能:
	// 1. T[i]和S[j]对齐，则子序列个数为之前的值, 即 dp[i-1][j-1]
	// 2. 否则，两者不能对齐, T[i]必须与S的前j-1个字符对齐, 则为 dp[i][j-1]
	// 而如果T[i]!=S[j],那么T[i]和S[j]不能对齐，只能是上述第2种情况
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (T[i-1] == S[j-1]) {
				dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
			} else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	
	return dp[n1][n2];
}

int main()
{
	string T = "rabbit";
	string S = "rabbbit";
	cout << numDistinct(S, T) << endl;
	return 0;
}
