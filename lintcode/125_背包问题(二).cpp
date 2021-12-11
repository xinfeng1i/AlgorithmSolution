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


/** 
 * ���䱳�����⣺
 * dp[i][j]: ����i����Ʒ��j��С�ռ����ܴ�ŵ�����ֵ
 * ״̬ת�ƣ�
 * dp[i][j] = dp[i-1][j-thisSize] + V[i]  select the ith item
 *          = dp[i-1][j]  otherwise
 * Note: if thisSize > j, then only the second equation can keep.
 * ʱ�临�Ӷȣ�O(n*m)
 * �ռ临�Ӷȣ�O(n*m)
 */
int backPackII(int m, vector<int>& A, vector<int>& V) {
    if (A.empty()) return 0;
    assert(A.size() == V.size());
    int n = (int)A.size();

    // init
    vector<vector<int>> dp;
    for (int i = 0; i <= n; ++i) {
        vector<int> temp(m + 1, 0);
        dp.push_back(temp);
    }
    // ��������Ϊ0ʱ������ֵ��Ϊ0
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    // ��Ʒ����Ϊ0ʱ������ֵΪ0
    for (int j = 0; j <= m; ++j) dp[0][j] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int thisValue = V[i - 1];
            int thisSize = A[i - 1];
            if (thisSize > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                int temp1 = dp[i - 1][j - thisSize] + thisValue;
                int temp2 = dp[i - 1][j];
                dp[i][j] = max(temp1, temp2);
            }
        }
    }

    return dp[n][m];
}

