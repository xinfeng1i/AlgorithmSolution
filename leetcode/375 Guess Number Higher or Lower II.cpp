#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define Method2

#if Method1
// 记忆化搜索方法
int CalcCost(int l, int r, int** mem) {
	if (l >= r) return 0; // no number or only one number
	if (mem[l][r] != -1) return mem[l][r];
	int ansA = INT_MAX;
	for (int k = l; k <= r; ++k) {
		int cost1 = CalcCost(l, k-1, mem) + k;
		int cost2 = CalcCost(k+1, r, mem) + k;
		int ansB = max(cost1, cost2);
		ansA = min(ansA, ansB);
	}
	mem[l][r] = ansA;
	return ansA;
}

int getMoneyAmount(int n) {
	const int N = 505;
	int** mem = new int*[N];
	for (int i = 0; i < N; ++i) mem[i] = new int[N];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			mem[i][j] = -1;
		}
	}
	int ans = CalcCost(1, n, mem);
	for (int i = 0; i < N; ++i) delete[] mem[i];
	delete[] mem;
	return ans;
}
#endif // Method1


// 动态规划：Bottom to Up
// F[L][R] = 在区间[L, R]内猜数字需要的最小代价
// F[L][R] = min_k max(F[L, k-1]+k, F[k+1, R]+k)
#ifdef Method2
int getMoneyAmount(int n) {
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for (int l = n; l >= 1; --l) {
		for (int r = 1; r <= n; ++r) {
			if (l <= r) {
				if (l == r) {dp[l][r] = 0; continue;}
				//cout << "l=" << l << " r=" << r << endl;
				dp[l][r] = INT_MAX;
				for (int k = l; k <= r; ++k) {
					int temp = 0;
					if (k == l) temp = dp[k+1][r]+k;
					else if (k == r) temp = dp[l][k-1]+k;
					else temp = max(dp[l][k-1]+k, dp[k+1][r]+k);
					dp[l][r] = min(dp[l][r], temp);
				}
			}
		}
	}
	return dp[1][n];
}
#endif // Method2


int main()
{
	cout << getMoneyAmount(10) << endl;
	return 0;
}
