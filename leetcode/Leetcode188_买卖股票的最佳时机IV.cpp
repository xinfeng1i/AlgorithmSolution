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


void printDPMat(vector<vector<int>> m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * ״̬���壺dp[i][k][0,1] ��ʾ����i��Ϊֹ�������k�ν��׻��������£�
            ������״̬��0�������У�/1(���У�������µ��������
 * ���Ŀ�꣺dp[n][k][0]
 * ״̬ת�ƣ�
 *     dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
 *     dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
 * ��ʼ������
 *     dp[i=0][k][1] = INT_MIN
 *     dp[i=0][k][0] = 0
 * ʱ�临�Ӷȣ�O(n*k)
 * �ռ临�Ӷȣ�O(n*k)
 */
int maxProfit(int k, vector<int>& prices) {
    int n = (int)prices.size();

    vector<vector<int>> dp0(n + 1, vector<int>(k + 1, 0));
    vector<vector<int>> dp1(n + 1, vector<int>(k + 1, 0));
    for (int j = 0; j <= k; ++j) dp1[0][j] = INT_MIN;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp0[i][j] = max(dp0[i - 1][j], dp1[i - 1][j] + prices[i - 1]);
            dp1[i][j] = max(dp1[i - 1][j], dp0[i - 1][j - 1] - prices[i - 1]);
        }
    }

    return dp0[n][k];
}

int main() {
    int k1 = 2;
    vector<int> v1 = { 2,4,1 };
    int ans1 = maxProfit(k1, v1);

    cout << ans1 << endl;

    int k2 = 2;
    vector<int> v2 = { 3,2,6,5,0,3 };
    int ans2 = maxProfit(k2, v2);

    cout << ans2 << endl;

    return 0;
}