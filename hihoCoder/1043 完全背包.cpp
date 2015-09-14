#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXN 510
#define MAXM 100010

int need[MAXN];
int value[MAXN];
int dp[MAXN][MAXM];

int q0[MAXM];
int q1[MAXM];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &need[i], &value[i]);
	}
	
	// dp[i][j] = 用j张奖卷选择前i中商品最多能够得到的价值
	// 则对于第i种商品有两种情况，完全不选择第i种商品
	// dp[i][j] = dp[i-1][j]
	// 至少选择一种第i种商品
	// dp[i][j] = dp[i][j-need[i]] + value[i]
	// 从而 dp[i][j] = max{dp[i-1][j], dp[i][j-need[i]] + value[i]}
	// 初始化: dp[i][0] = 0; dp[0][j] = 0;
	for (int j = 0; j <= m; ++j) dp[0][j] = 0;
	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j >= need[i]) {
				dp[i][j] = max(dp[i-1][j], dp[i][j-need[i]] + value[i]);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	printf("%d\n", dp[n][m]);

	// 优化空间复杂度, 由于每一行的当前值仅仅依赖于前一行的值和当前行的前面列
    // 的值，所以可以用2行来交替存储, 下面优化后的代码空间复杂度为 O(2 * m)
    /*
    for (int j = 0; j <= m; ++j) {
		q0[j] = 0;
		q1[j] = 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i % 2 == 1) {
				if (j >= need[i]) {
					q1[j] = max(q0[j], q1[j-need[i]] + value[i]);
				} else {
					q1[j] = q0[j];
				}
			} else {
				if (j >= need[i]) {
					q0[j] = max(q1[j], q0[j-need[i]] + value[i]);
				} else {
					q0[j] = q1[j];
				}
			}
		}
	}
	
	int ans = n % 2 == 1 ? q1[m] : q0[m];
	printf("%d\n", ans);
	*/
	
	return 0;
}
