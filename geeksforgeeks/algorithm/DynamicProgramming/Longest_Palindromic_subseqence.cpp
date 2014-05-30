#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 最长回文子串
 * 给定一个字符串，找到长度最长的回文子串(不要求连续)
 * 例如："BBABCBCAB", 最长回文子串是"BABCBAB",输出长度7
 */

/*
 * 问题分析：
 * 定义L[i,j]表示子串i...j的最长回文子串长度，则原问题等价于求解L[0, n-1]
 * 如果s[i]==s[j] 则 L[i,j] = L[i+1,j-1]  + 2;
 * 否则s[i]!=s[j] 则 L[i,j] = max{L(i, j-1), L(i+1,j)};
 * 初始条件：
 * L[i,i] = 1;
 * if j = i + 1 //只有两个字符 L[i,j] = (s[i]==s[j] ? 2:1)
 * 
 * 依赖关系如下所示，由于依赖左下方数据，不能按照普通的行优先或者
 * 列优先的方式求解，必须按照对角线的方式求解，类似于矩阵链式相乘
 * 具体说来，按照串长度循环
 * [i][j-1] --- [i][j]
 *             /  |
 *			  /   |
 * [i+1][j-1]   [i+1][j]  
 */

int LPS(string s)
{
	int n = s.size();
	int L[n][n];

	//init
	for (int i = 0; i < n; ++i) L[i][i] = 1;

	// bottom to up, triangle mode
	for (int l = 2; l <= n; ++l)
	{
		for (int i = 0; i <= n - l; ++i)
		{
			int j = i + l - 1;
			if (l == 2 && s[i] == s[j])
			{
				L[i][j] = 2;
			}
			else if (s[i] == s[j])
			{
				L[i][j] = L[i+1][j-1] + 2; // init
			}
			else
			{
				L[i][j] = max(L[i+1][j], L[i][j-1]);
			}
			
		}
	}

	return L[0][n-1];
}
/*
 * 复杂度分析：
 * 时间空间复杂度均为O(n^2)
 */
/*
 * 坑点：基本情况的考虑子串长度为2时，s[i]==s[j],直接return 2
 */


/* 其他思路：
 * 转化成最长公共子列问题LCS
 * 将原字符串反转后存在辅助字符串s2中，则原问题等价于求解
 * LCS(s, s2)
 */

int main()
{
	string s;
	cin >> s;
	int ans = LPS(s);
	cout << ans << endl;
	return 0;
}
