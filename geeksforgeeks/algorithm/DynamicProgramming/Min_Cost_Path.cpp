#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * 问题描述：
 * 给定一个矩阵m * n, 矩阵中的每个数字表示经过该方格时的代价，计算从初始点
 * [0,0] 到 [m,n]的最小代价？如果当前在[i,j]则下一步只能位于[i+1,j] 
 * [i, j+1], [i+1,j+1]三个方格之一
 */

/* 
 * 问题分析：
 * 定义E[i,j]表示从[0,0]到[i,j]的最小代价则
 * E[i,j] = E[i-1,j-1] + cost[i,j] 或者
 * E[i,j] = E[i-1,j] + cost[i,j] 或者
 * E[i,j] = E[i, j-1] + cost[i,j]
 *
 * 初始条件：
 * E[0,0] = cost[0,0];
 * E[0,j] = cost[0, j-1] + cost[0,j];
 * E[i,0] = cost[i-1, 0] + cost[i, 0];
 */

int min_three(int a, int b, int c)
{
	return min(min(a, b), c);
}

int MinCostPath(int cost[3][3], int m, int n)
{
	int E[m][n];
	
	// init
	E[0][0] = cost[0][0];
	for (int j = 1; j < n; ++j) E[0][j] = E[0][j-1] + cost[0][j];
	for (int i = 1; i < m; ++i) E[i][0] = E[i-1][0] + cost[i][0];

	// bottom to up
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			int a1 = E[i-1][j-1] + cost[i][j];
			int a2 = E[i-1][j] + cost[i][j];
			int a3 = E[i][j-1] + cost[i][j];
			E[i][j] = min_three(a1, a2, a3);
		}
	}

	return E[m-1][n-1];
}
/*
 * 复杂度分析;
 * 时间复杂度和空间复杂度都是O(mn)
 */

int main()
{
	int cost[3][3] = { {1, 2, 3},
					   {4, 8, 2},
					   {1, 5, 3} };
	int ans = MinCostPath(cost, 3, 3);
	cout << "Min Cost Path : " << ans << endl;
	return 0;
}
