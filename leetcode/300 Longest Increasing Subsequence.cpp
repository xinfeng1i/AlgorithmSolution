#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

// dp[i] 表示以A[i]结尾的LIS的长度
// 则 dp[i] = max{dp[j] + 1} if A[i] > A[j]
int lengthOfLIS(vector<int>& A) {
	if (A.empty()) return 0;
	int n = (int)A.size();
	
	vector<int> dp(n, 0);
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	
}
