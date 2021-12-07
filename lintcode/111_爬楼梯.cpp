#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


// 定义 dp[n] 表示爬上第 n 个台阶的方法数
// 则: dp[n] = dp[n-1] + dp[n-2]
// 初始值: dp[1] = 1, dp[2] = 2
//
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int climbStairs(int n) {
    if (n <= 2) return n;  // 注意考虑base case，否则会出现segment fault错误

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

#if 0
int main() {
    cout << climbStairs(3) << endl;
    return 0;
}
#endif // 0