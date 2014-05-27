#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * 01背包问题：
 * 有n件物品，重量由weight[0...n-1]数组给出，价值由value[0...n-1]数组给出,
 * 现在给定一个背包最大能够放W重量的物品
 * 问选择放哪些物品到背包使得所得到的价值最大？
 */

/*
 * 基本思路：
 * 假设V[i][j]表示将前i件物品放进重量为j的背包内所能得到的最大价值
 * 考虑最后一件物品要么包含在内，要么不包含在内
 * 如果不包含在内，则相当于是求解V[i-1][j];
 * 如果包含在内，V[i][j] = V[i-1][j-weight[i-1]] + value[i-1]; j>=weight[i-1]
 * 从而状态转移方程为：
 * V[i][j] = max{v[i-1][j], v[i-1][j-weight[i-1]+value[i-1]}
 * 初始条件为：
 * V[i][0] = 0;
 * V[0][j] = 0;
 */

int KnapSack(int weight[], int value[], int n,  int W)
{
	int dp[n+1][W+1];

	// init 
	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	for (int j = 0; j <= W; ++j) dp[0][j] = 0;

	// bottom to up
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			if (j >= weight[i-1])
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];	
			}
		}
	}

	return dp[n][W];
}
/*
 * 时间复杂度和空间复杂度均为：O(nW)
 */

int main()
{
	int val[] = {60, 100, 120};
	int wt[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(val)/(sizeof(val[0]));
	int ans = KnapSack(wt, val, n, W);
	cout << ans << endl;
	return 0;
}
