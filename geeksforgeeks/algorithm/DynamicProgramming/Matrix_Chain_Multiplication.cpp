#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX_VALUE = 30000;

/*
 * 问题描述：
 * 给定一个数组p[]表示链式矩阵，其中第i个矩阵是p[i-1]*p[i]维的，
 * 找到计算矩阵乘积所需要的最少乘法次数
 */

/*
 * 定义dp[i][j]表示链式矩阵Ai...Aj相乘所需要的最少乘法次数
 * 假设最后一次乘法出现在第Ak个矩阵处，即
 * (Ai...Ak)(Ak+1...Aj)
 * 则 dp[i][j] = min{dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]}
 *
 * 初始条件：
 * j >= i
 * dp[i][i] = 0;
 * dp[0][j] = 0;
 * dp[i][0] = 0;
 */

// n 表示链表的长度A1...An
int MatrixChainMultiplication(int p[], int n)
{
	int dp[n+1][n+1];

	// init
	for (int i = 0; i <= n; ++i) dp[i][i] = 0;

	// bottom to up
	// L 表示链表Ai...Aj的长度
	for (int L = 2; L <= n; ++L)
	{
		for (int i = 1; i <= n+1-L; ++i)
		{
			int j = i + L - 1;
			int mymin = MAX_VALUE;
			for (int k = i; k + 1 <= j; ++k)
			{
				int tmp = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
				mymin = min(mymin, tmp);
			}
			dp[i][j] = mymin;
		}
	}
	return dp[1][n];
}
/*
 * 复杂度分析：
 * 时间复杂度O(n^3)
 * 空间复杂度O(n^2)
 */

int main()
{
	int p[] = {40, 20, 30, 10, 30};
	//int p[] = {10, 20, 30, 40, 30};
	//int p[] = {10, 20, 30};
	int ans = MatrixChainMultiplication(p, 4);
	cout << "Matrix Chain Multiplication: " << ans << endl;
	return 0;
}
