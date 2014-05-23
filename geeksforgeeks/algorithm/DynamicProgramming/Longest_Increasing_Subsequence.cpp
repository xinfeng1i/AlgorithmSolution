#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

/*
 * 问题描述：
 * 找到最长的自序列(可以不连续)，使得子列中所有的元素以增序的方式排列
 *
 * 例如
 * 输入：{10, 22, 9, 33, 21, 50, 41, 60. 80}
 * 输出：{10, 22, 33, 50, 60, 80}
 */

/***************Wrong Answer******************************************
 * dp[j] = 到第j个元素为止的最长子列的元素个数
 * dp[j] = dp[j-1]			if dp[j] < max[j-1];
 * dp[j] = dp[j-1] + 1,		else dp[j] > max[j-1];
 * 初始条件： dp[1] = 1;
 *
 * max[j] = 到第j个元素为止的子列中，元素的最大值
 * max[j] = max[j-1]		if a[j] < max[j-1];
 * max[j] = a[j]			else a[j] > max[j-1];
 * 初始条件：max[1] = a[1]
 *
 * 这种方法假设最长子列一定从第一个元素作为起始元素，因而对于输入
 * Input: {10, 1, 2, 3, 4, 5}
 * Output: {10} 而不是 {1, 2, 3, 4, 5} 
 ********************************************************************/

/*************************Right Answer*******************************
 *	Lis[i] 表示以a[i]结尾的最长子列的长度 
 *  Lis[i] = max(Lis[j] + 1) if a[j] < a[i], for j < i;
 *
 *  问题的答案等价于求解
 *  max{Lis[i]} for i = 0:n
 *
 *  初始条件：
 *  Lis[i] = 1; for i=0:n;
 ********************************************************************/

/*
 * Longest Increasing Subsequece
 *
 * Parameters:
 *		a -- input array
 *		prev -- prev[i]表示以i结尾的最长子列的前驱元素索引
 *		ending_here -- 记录在LIS结束于哪个位置
 * Return:
 *		the length of the LIS
 */
int LIS(const vector<int>& a, vector<int>& prev, int& ending_here)
{
	int n = a.size();

	vector<int> lis(n, 0);
	// init
	for (int i = 0; i < n; ++i)
	{
		lis[i] = 1;

		// to find a specific solution
		prev[i] = i;
	}

	// DP, bottom to up, compute all Lis[i] for i = 0 : n;
	for (int i = 1; i < n; ++i)
	{
		lis[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (a[j] < a[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
	}

	int ans = 0; 
	ending_here = -1;
	for (int i = 0; i < n; ++i)
	{
		if (lis[i] > ans)
		{
			ans = lis[i];
			ending_here = i;
		}

	}

	return ans;
}

int main()
{
	int a1[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int a2[] = {10, 1, 2, 3, 4, 5, 0};
	const int n2 = 7;
	vector<int> v1(a1, a1 + 9);
	vector<int> prev1(9); int ending_here_1;
	vector<int> v2(a2, a2 + n2 );
	vector<int> prev2(n2); int ending_here_2;

	int ans1 = LIS(v1, prev1, ending_here_1); 
	int ans2 = LIS(v2, prev2, ending_here_2);
	cout << "LIS 1: " << ans1 << endl;
	cout << "LIS 2: " << ans2 << endl;

	cout << "LIS 1 list: " << endl;
	int last; stack<int> s1;
	for (last = ending_here_1; prev1[last] != last; last = prev1[last])
	{
		//cout << " " << a1[last];
		s1.push(a1[last]);
	}
	s1.push(a1[last]);

	while(!s1.empty())
	{
		cout << " " << s1.top();
		s1.pop();
	}
	cout << endl;
	
	

	cout << "LIS 2 list: " << endl;
	/*
	for (int i = 0; i < prev2.size(); ++i)
	{
		cout << " " << prev2[i];
	}
	cout << endl;
	*/
	
	int last2; stack<int> s2;
	for (last2 = ending_here_2; prev2[last2] != last2; last2 = prev2[last2])
	{
		//cout << " " << a2[last2];
		s2.push(a2[last2]);
	}
	s2.push(a2[last2]);

	while(!s2.empty())
	{
		cout << " " << s2.top();
		s2.pop();
	}
	cout << endl;
	return 0;
}
