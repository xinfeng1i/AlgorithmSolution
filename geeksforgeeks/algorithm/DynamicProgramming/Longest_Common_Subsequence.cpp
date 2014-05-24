#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
 * 最长公共子列
 *
 * 问题描述：
 * 给定两个子列，找到他们的最长公共子列的长度，子列只要求保持相对位置不变
 * 例如：acf 是 abcdefg的一个子列
 */

/*
 * 问题解决思路：
 * 考虑两个序列 X[0...m-1] 和 Y[0...n-1]的最后一个字母是否被LCS匹配到？
 * 如果被匹配到(X[m-1] == Y[n-1]) 则
 * LCS(x[0...m-1], Y[0...n-1]) = 1 + LCS(x[0...m-2], Y[0...n-2]);
 * 如果没有被匹配到(X[m-1] != Y[n-1]) 则
 * LCS(x[0...m-1], Y[0...n-1] = max{LCS(X[0...m-1], Y[0...n-2]), LCS(X[0...m-2],Y[0...n-1])}
 *
 * 初始条件：如果其中一个子列长度为0，则LCS=0；
 */

/* 定义L[i][j]表示X[0...i-1] 和 Y[0...j-1]的LCS
 *
 * 则 L[0][j] = 0 for all j
 *    L[i][0] = 0 for all i
 * LCS(X, Y) = L[m][n]
 *
 * 注意：L[i][j]表示的长度为i的X和长度为j的Y的LCS
 *       因此维度要比以前的数组各加1，注意边界情况
 */

int LCS(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];
	//vector<vector<int> > L(m + 1, vector<int>(n + 1));

	// init
	for (int j = 0; j <= n; ++j) L[0][j] = 0;
	for (int i = 0; i <= m; ++i) L[i][0] = 0;

	// DP by bottom to up 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (X[i-1] == Y[j-1])
			{
				L[i][j] = 1 + L[i-1][j-1];
			}
			else
			{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	// print the LCS;
	int ii = m; int jj = n;
	int index = L[m][n];
	
	char lcs[index+1]; lcs[index] = '\0';
	while(ii > 0 && jj > 0)
	{
		if (X[ii-1] == Y[jj-1])
		{
			lcs[index-1] = X[ii-1];
			ii--;
			jj--;
			index--;
		}
		else if (L[ii-1][jj] > L[ii][jj-1])
		{
			ii--;
		}
		else
		{
			jj--;
		}
	}

	cout << "The LCS is: " << lcs << endl;

	/*
	// print table
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout <<" " << L[i][j];
		}
		cout << endl;
	}
	*/

	return L[m][n];
}
/* 复杂度分析：
 * 时间复杂度：O(mn)
 * 空间复杂度：O(mn)
 */

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	int ans = LCS(X, Y, m, n);
	
	cout << "The Length of LCS is : " << ans << endl;
	return 0;
}
