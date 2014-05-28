#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*
 * 问题描述：
 * 有n个鸡蛋，k层高的大楼，想要知道在那些楼丢下鸡蛋不会碎，哪些楼丢下
 * 鸡蛋会碎
 *
 * 基本假设如下：
 * 假设1：如果鸡蛋掉下没有碎，可以再次使用
 * 假设2：如果鸡蛋碎了，只能丢弃
 * 假设3：所有鸡蛋完全相同
 * 假设4：如果鸡蛋在第x层摔碎，则在任何大于x层必然也摔碎
 * 假设5：如果鸡蛋在第x层完好，则在任何小于x层必然完好
 * 假设6：不排除第一层楼就摔碎鸡蛋，也不排除最高层鸡蛋不摔碎
 */

/*
 * 问题分析：
 * 假设只有一个鸡蛋，需要测试36层楼，在哪一层楼鸡蛋刚好会碎，
 * 方法只有是在第一层测试一下，然后到第二层测试一下，再到第三层
 * 等等测试。
 * 如果有两个鸡蛋，需要测试36层楼，这时应该如何测试呢？
 * 更一般的如果有n个鸡蛋，需要测试的楼层高为k如何测试？
 * 
 * 假设在x层楼丢下一个鸡蛋，则可能的结果有两种：
 * 1. 鸡蛋摔碎，则问题转化为利用剩下的n-1个鸡蛋测试x-1层楼
 * 2. 鸡蛋没有摔碎，则问题转化为测试剩余的k-x层楼，用n个鸡蛋
 *  
 * 定义ED[i][j]表示用i个鸡蛋，测试高度为j的楼层所需要的最少测试数
 * 则由前面的分析假设我们知道最佳方案第一个鸡蛋应该在第x层楼扔下，
 * 这样对于得到的两个子问题总是假设处理最坏的子问题，而实际我们并不
 * 知道最佳x，这时需要x遍历所有楼层找出所有最坏情况中的最优解
 *
 * 状态转移方程：
 * E[i][j] = 1 + min { max{E[i-1][x-1], E[i][j-x]} } ; x->1:j
 * 原问题等价求解E[n][k]
 *
 * 初始条件：
 * E[0][j] = 0; // 如果没有鸡蛋，不管楼层有多高，无法测试
 * E[1][j] = j; // 用一个鸡蛋测试j层楼，最坏的情况需要测试j次
 * E[i][0] = 0; // 不管有多少个鸡蛋，在第0层不需要测试
 * 
 */
 const int MAX_VALUE = 30000;
 int EggDrop(int n, int k)
 {
 	int E[n+1][k+1];

 	// init
 	for (int j = 0; j <= k; ++j) E[0][j] = 0;
 	for (int i = 1; i <= n; ++i) E[i][1] = 1; // 1个楼层，不管多少个鸡蛋，只需要1次测试
 	for (int i = 0; i <= n; ++i) E[i][0] = 0; // 0个楼层，需要0次测试
 	for (int j = 0; j <= k; ++j) E[1][j] = j; // 1个鸡蛋j层楼需要测试j次

 	// bottom to up
 	for (int i = 2; i <= n; ++i)
 	{
 		for (int j = 2; j <= k; ++j)
 		{
 			E[i][j] = MAX_VALUE;
 			for (int x = 1; x <= j; ++x)
 			{
 				E[i][j] = min( max(E[i-1][x-1], E[i][j-x])+1, E[i][j]);
 			}
 		}

 	}

 	// print dp array
 	/*
 	cout << "DP Array" << endl;
 	for (int i = 0; i <= n; ++i)
 	{
 		for (int j = 0; j <= k; ++j)
 		{
 			cout << " " << E[i][j];
 		}
 		cout << endl;

 	}
 	cout << endl;
 	*/

 	return E[n][k];
 }
 /*
  * 复杂度分析：
  * 空间复杂度O(nk)
  * 时间复杂度O(nk^2)
  */
  /* 坑点：注意初始条件 */

int main()
{
	cout << "Enter n & k" << endl;
	int n, k;
	cin >> n >> k;
	int ans = EggDrop(n, k);
	cout << ans << endl;
	return 0;
}