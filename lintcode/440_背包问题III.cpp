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
 * ��ȫ��������
 * ״̬���� dp[m]������ m �ı������ܴ�ŵ�����ֵ
 * ״̬ת�ƣ�����ÿһ����Ʒ i�����뱳������ѡ�������ֵ�����ֵ
 *          dp[m] = max_i dp[m-size_i] + v[i]
 * ��ʼֵ��dp[0] = 0
 * ʱ�临�Ӷȣ�O(m * n)
 * �ռ临�Ӷȣ�O(m)
 */
int backPackIII(vector<int>& A, vector<int>& V, int m) {
    if (A.empty()) return 0;
    if (m == 0) return 0;
    int n = (int)A.size();

    // dp[m]: ����Ϊm�ı����ܷŵ�����ֵ
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        // ����ÿһ����Ʒ
        int maxValue = 0;
        for (int j = 0; j < n; ++j) {
            int thisSize = A[j];
            int thisValue = V[j];
            if (thisSize <= i) {
                maxValue = max(maxValue, dp[i - thisSize] + thisValue);
            }
        }
        dp[i] = maxValue;
    }

    return dp[m];
}