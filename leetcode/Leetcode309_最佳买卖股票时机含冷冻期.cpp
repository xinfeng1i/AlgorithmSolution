#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


void printVec(vector<int>& v) {
    for (int x : v) {
        cout << " " << x;
    }
    cout << endl;
}

//***********************************************************************
// ״̬���壺
//     dp[i][0]: ����i��λ�ã�״̬Ϊ������/���й�Ʊ������»�ȡ���������
// ״̬ת��:
//     dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]
//     dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]
//                                ע�⣺����������CD�ڣ�������������CD��
// ��ʼ״̬��
//     dp[0][1] = INT_MIN
//     dp[1][1] = -prices[1]
//***********************************************************************
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    vector<int> dp0(n + 1, 0);
    vector<int> dp1(n + 1, 0);

    dp1[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i - 1]);

        if (i >= 2) {
            dp1[i] = max(dp1[i - 1], dp0[i - 2] - prices[i - 1]);
        } else {
            // ע�������ʼ����
            dp1[i] = -prices[i - 1];
        }
    }

    return max(dp1[n], dp0[n]);
}


int main() {
    vector<int> v = { 1,2,3,0,2 };
    int ans = maxProfit(v);
    cout << ans << endl;  // expected: 3
    return 0;
}