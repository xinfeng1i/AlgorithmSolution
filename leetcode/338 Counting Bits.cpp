// 000    0
// 001    1
// 010    1
// 011    2
// 100    1
// 101    2
// 110    2
// 111    3
// 规律：第一个数有0个1，接下来1个数有[1]个1，接下来两个数[2, 3]分别是在其前两个书[0, 1]的基础上增加了一个1
// 接下来的四个数[4,5,6,7]实在前面四个数的基础上增加了一个1，因此可以bottom to up计算
vector<int> countBits(int n) {
	// 注意此种方法求出的是所有2的整数次方-1的元素个数，因此
    // 注意初始化是数组的长度和最后的resize
    vector<int> F(2 * n, 0);
    int cur = 0;
    int fact = 1;
    while (cur < n) {
        for (int k = 1; k <= fact; ++k) {
            cur++;
            F[cur] = F[cur - fact] + 1;
        }
        fact *= 2;
    }

    F.resize(n+1);
    return F;
}
