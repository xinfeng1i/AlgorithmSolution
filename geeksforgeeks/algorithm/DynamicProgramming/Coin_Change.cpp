#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * 问题描述：
 * 给定一组硬币面值分别为{S1, S2, ..., Sm}，需要找回零钱N, 问总共有多少种
 * 找零法？
 */

/*
 * 问题分析：
 * 定义C[m, n]表示 用前m中硬币找零n的方法数
 * 则原问题可以分为两个子问题，找零中包含和不包含Sm
 * 假设不包含Sm,则总共有C[m-1, n]种找零法
 * 假设包含Sm, 则C[m, n-Sm]种找零法 
 * 从而
 * C[m,n] = C[m-1, n] + C[m, n-Sm]
 *
 * 初始条件：
 * C[0, n] = 0;
 * C[m, 0] = 1;
 */

int CoinChange(int S[], int m, int n)
{
	int C[m+1][n+1];

	// init
	for (int i = 0; i <= m; ++i) C[i][0] = 1;
	for (int j = 0; j <= n; ++j) C[0][j] = 0;

	// bottom to up
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j >= S[i-1])
			{
				C[i][j] = C[i-1][j] + C[i][j-S[i-1]];
			}
			else
			{
				C[i][j] = C[i-1][j];
			}
		}
	}

	return C[m][n];
}
/*
 * 复杂度分析：
 * 时间，空间复杂度都是O(mn)
 */

int main()
{
	//int S[] = {1, 2, 3};
	int S[] = {2, 3, 5, 6};
	//int ans = CoinChange(S, 3, 4);
	int ans = CoinChange(S, 4, 10);
	cout << "The number of changing Coins:" << ans << endl;
	return 0;
}
