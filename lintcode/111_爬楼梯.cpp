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


// ���� dp[n] ��ʾ���ϵ� n ��̨�׵ķ�����
// ��: dp[n] = dp[n-1] + dp[n-2]
// ��ʼֵ: dp[1] = 1, dp[2] = 2
//
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
int climbStairs(int n) {
    if (n <= 2) return n;  // ע�⿼��base case����������segment fault����

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