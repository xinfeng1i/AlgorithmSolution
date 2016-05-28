// 动态规划
// 令 F(n) = 用完全平方数和表示n所需要的最少完全平方数
// 则必然有完全平方数x, F(n-x) + 1 = F(n)
// 遍历所有的x，取最小值即可
// 因为任意的整数n可以由n个1表示，所以初值可以为F(n) = n;
int numSquares(int n) {
    vector<int> F(n+1, 0);
    // init values
    for (int i = 0; i <= n; ++i) F[i] = i;

    // bottom to up
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            int x = j * j;
            F[i] = min(F[i], 1 + F[i-x]);
        }
    }

    return F[n];

}
