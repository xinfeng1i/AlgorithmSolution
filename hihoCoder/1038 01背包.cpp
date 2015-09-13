#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXN 600
#define MAXM 100010

int need[MAXN];
int value[MAXN];
int dp[MAXN][MAXM];

int q0[MAXM];
int q1[MAXM];

// 经典的 01背包问题
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &need[i], &value[i]);
	}
	
	// dp[i][j] = 用最多j张奖卷选择前i件物品所能取得的最大价值
	// 对于第i件物品只有两种选择，不选择或者选择
    // 如果不选择，则 dp[i][j] = dp[i-1][j]
    // 如果选择, 则 dp[i][j] = dp[i-1][j-need[i]] + value[i];
	// 则原问题等价于求解 dp[N][M]
	// 初始化条件 dp[i][0] = 0 dp[0][j] = 0
	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	for (int j = 0; j <= m; ++j) dp[0][j] = 0;
	
	// 时间和空间复杂度均为 O(nm)
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j >= need[i]) {
				dp[i][j] = max(dp[i-1][j-need[i]] + value[i], dp[i-1][j]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	printf("%d\n", dp[n][m]);

	
	// 由于下一行的计算仅仅依赖于上一行, 所以可以只用两行在存储结果并交替使用
	// 下面注释掉的代码是空间复杂度为 O(2 * m),
	/*
	for (int j = 0; j <= m; ++j) {
		q0[j] = 0;
		q1[j] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i % 2 == 1) {
				if (j >= need[i]) {
					q1[j] = max(q0[j-need[i]] + value[i], q0[j]);
				} else {
					q1[j] = q0[j];
				}
			} else {
				if (j >= need[i]) {
					q0[j] = max(q1[j-need[i]] + value[i], q1[j]);
				} else {
					q0[j] = q1[j];
				}
			}
		}
	}
	int ans = (n % 2 == 1 ? q1[m] : q0[m]);
	printf("%d\n", ans);
	*/
	
	return 0;
}
