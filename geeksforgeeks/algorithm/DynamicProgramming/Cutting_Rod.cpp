#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 问题描述：割绳子
 * 给定长度为n的绳子，并且给出长度分别为1,2,...,n的绳子能卖出的价钱，
 * 求解最优的切割方法，使得长度为n的绳子采用该方法后，能够卖到最高的价钱
 */
/* 问题分析：
 * 如果对于长度为n的绳子，在任意位置j切割以下，则得到两段绳子，从而
 * dp[n] = max{dp[j] + dp[n-j]} 
 * 由于不知道在哪里切割能够得到最大值，所以遍历j
 *
 * 状态转移：
 * dp[i]表示长度为i的绳子能卖出的最大价钱
 * dp[i] = max{dp[j] + dp[n-j]} j = 1,2,...i-1
 * 初始条件: 长度为i的绳子初始不切割直接卖出，如果碰到更优的，则update
 * dp[i] = price[i-1]
 */

int maxValue(int n, int price[])
{
	vector<int> dp(n+1);

	// init
	for (int i = 1; i <= n; ++i)
	{
		dp[i] = price[i-1];
	}


	// bottom to up
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i - 1; ++j)
		{
			if (dp[j] + dp[i-j] > dp[i])
			{
				dp[i] = dp[j] + dp[i-j];
			}
		}
	}

	return dp[n];
}
/* Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

int main()
{
	int price1[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n1 = 8;
	int price2[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int n2 = 8;

	int ans1 = maxValue(n1, price1);
	int ans2 = maxValue(n2, price2);
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}

