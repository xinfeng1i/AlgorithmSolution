#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
 * 编辑距离：
 * 问题描述：
 * 给定两个字符串长度为m，n，可以执行操作集replace(R), insert(I), delete(D)
 * 问最少需要多少操作？把一个字符串转换成另一个字符串
 */

/*
 * 题目分析：
 * 定义字符串X[1...i] Y[1...j]的编辑距离为E[i,j],则原问题等价于求解E[m,n]
 * 考虑X[1...i]和Y[1...j]的最后一个字符的对齐方式，分为三种情况
 * [i,j]对齐，则E[i,j] = E[i-1, j-1] + (X[i]==Y[j] ? 0 : ReplaceCost);
 * [i,-]对齐，则E[i,j] = E[i-1, j] + DeleteCost;
 * [-,j]对齐, 则E[i,j] = E[i, j-1] + InsertCost;
 *
 * 初始条件：
 * 如果其中一个字符串为空串，则编辑距离为另一个字符串的长度
 * E[0, j] = j
 * E[i, 0] = i
 */

const int ReplaceCost = 1;
const int InsertCost = 1;
const int DeleteCost = 1;
int min_three(int a, int b, int c)
{
	return min(min(a, b), c);
}

int EditDistance(char X[], char Y[])
{
	int m = strlen(X);
	int n = strlen(Y);
	int E[m+1][n+1];
	
	// base case
	for (int j = 0; j <= n; ++j) E[0][j] = j;
	for (int i = 0; i <= m; ++i) E[i][0] = i;

	// bottom to up
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int cost1 = E[i-1][j-1] + (X[i-1] == Y[j-1] ? 0 : ReplaceCost);
			int cost2 = E[i-1][j] + DeleteCost;
			int cost3 = E[i][j-1] + InsertCost;
			E[i][j] = min_three(cost1, cost2, cost3);
		}
	}

	// print the table
	/*
	cout << "m=" << m << "; n=" << n << endl;
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			cout << " " << E[i][j];
		}
		cout << "\n";
	}
	cout << endl;
	*/

	return E[m][n];
}
/* 
 * 复杂度分析：
 * 时间复杂度：O(mn)
 * 空间复杂度：O(mn)
 */

int main()
{
	char X[] = "SUNDAY";
	char Y[] = "SATURDAY";
	int d = EditDistance(X, Y);
	cout << "The Edit Distance is : " << d << endl;
	return 0;
}
