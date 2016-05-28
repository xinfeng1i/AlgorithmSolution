// 动态规划：
// n 可以分为x 和 n-x两部分，计算两部分的最大乘积，然后再相乘即可
// 即 dp[n] = max_{x} dp[x] * dp[n-x]  其中x=1,2,3...sqrt(n)
// 定义dp[n] 表示dp[n]整数分割后所能得到的最大乘积
// dp[1] = 1; dp[2] = 1;
int integerBreak(int n) {
    vector<int> dp(n+1, 1);
    dp[1] = 1; // 为方便计算强制规定
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = 1 * (i-1);
        for (int k = 1; k <= i-1; ++k) {
            dp[i] = max(dp[i], max(k, dp[k]) * max(i-k, dp[i-k])); // note the special case which means that k may not break any more
        }
    }
    return dp[n];
}
