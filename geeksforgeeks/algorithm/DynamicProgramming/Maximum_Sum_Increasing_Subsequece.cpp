#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 问题描述： 最长递增子列和
 * 给定一个数组a[],所有元素都是正数，找到一个最长的子列，满足该子列是递增
 * 的并且和最大
 * 例如： 输入 {1, 101, 2, 3, 100, 4, 5}
 *        输出 {1, 2, 3, 100} = 106
 *        输入 {10, 5, 4, 3}
 *        输出 {10} = 10
 */

/*
 * 问题分析
 * 此问题与最长递增子列一样，只是目标函数不同而已。
 * 定义 dp[i] = 以第i个元素为结尾的最大递增子列(子列包含a[i]且以a[i]结尾)
 * 则dp[i] - a[i] 则表示以j结尾的最大子增子列的最大值，其中j < i,a[i]>a[j]
 * 否则，如果能够找到更大和的子列，则加入a[i]必然得到以a[i]结尾的更大和
 * 的子列。
 * 即 dp[i] - a[i] = max{dp[j], j < i && a[j] < a[i]}
 *
 * 状态转移方程:
 * dp[i] = max{dp[j] + a[i]} j < i && a[j] < a[i]
 * 初始条件：
 * dp[i] = a[i], i = 0 : n-1
 */

int MaxSumIS(int a[], int n)
{
	vector<int> dp(n);

	//init
	for (int i = 0; i < n; ++i)
	{
		dp[i] = a[i];
	}

	// bottom to up
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (a[j] < a[i] && dp[j] + a[i] > dp[i])
			{
				dp[i] = dp[j] + a[i];
			}
		}
	}

	// compute ans
	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[i]);
	}

	return ans;
}
/* 时间复杂度：O(n^2)
 * 空间复杂度：O(n)
 */

int main()
{
	int a1[] = {1, 101, 2, 3, 100, 4, 5};
	int a2[] = {3, 4, 5, 10};
	int a3[] = {10, 5, 4, 3};

	int ans1 = MaxSumIS(a1, 7);
	int ans2 = MaxSumIS(a2, 4);
	int ans3 = MaxSumIS(a3, 4);

	cout << "ans1 : " << ans1 << endl;
	cout << "ans2 : " << ans2 << endl;
	cout << "ans3 : " << ans3 << endl;
	return 0;
}
