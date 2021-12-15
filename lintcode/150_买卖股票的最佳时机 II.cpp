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


/*
 * ʹ��̰���㷨��Ȼ���Եõ���ȷ�𰸣��ο����˵Ĵ𰸣���ԱȽ������
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷȣ�O(1)
 * ע�⣺
 * ���ַ���Ҳ����ȷ���� [1, 2, 5] ��������һ�����һ����������=5-1=4
 * ����ֵ��Ҳ����(2-1) + (5-2) = 4
 * ���Ǽ���Ĺ��̲����ڽ��׵Ĺ��̣������Ϊ���ӣ����������ε���ʵ�ʽ�����Ȼ��
 * ��һ�����룬���һ��������
 */
int maxProfitII_Method1(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int ans = 0;
    int n = (int)prices.size();
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}

/*
 * ʹ�������Ͷ�̬�滮��ö�������е㣬�Լ������Ľⷨ�����Ӷ�̫�߻���ɳ�ʱ
 * ʱ�临�Ӷȣ�O(n^3)
 * �ռ临�Ӷȣ�O(n^2)
 */
int maxProfitII_Method2(vector<int>& prices) {
    // dp[i][j]: ������[i, j] �����������ܵõ����������

    if (prices.size() <= 1) return 0;
    int n = (int)prices.size();
    vector<vector<int>> dp;
    for (int i = 0; i < n; ++i) {
        vector<int> temp(n, 0);
        dp.push_back(temp);
    }
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (prices[i + 1] > prices[i]) {
            dp[i][i + 1] = prices[i + 1] - prices[i];
        }
        else {
            dp[i][i + 1] = 0;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            // ö��ÿһ��������м��
            int maxValue = 0;
            for (int k = i; k < j; ++k) {
                maxValue = max(maxValue, dp[i][k] + dp[k + 1][j]);
            }
            // ������������ȡ�����ֵ
            int temp = prices[j] > prices[i] ? prices[j] - prices[i] : 0;
            maxValue = max(maxValue, temp);
            dp[i][j] = maxValue;
        }
    }
    return dp[0][n - 1];
}


/*
 * �ⷨ3����׼��̬�滮�ⷨ���ǳ������Ҫ�෴˼
 *
 * ����״̬��
 *    dp0[i]��ʾ�ڵ�i��������׺���иù�Ʊ��״̬�£���õ��������
 *    dp1[i]��ʾ�ڵ�i��������׺󲻳��иù�Ʊ��״̬�£����ܻ�õ��������
 * ״̬ת�ƣ�
 *    dp0[i] = dp1[i-1]-prices[i]  ��������
 *           = dp0[i-1]            ǰһ���Ѿ�����
 *    dp1[i] = dp0[i-1]+prices[i]  ��������
 *             dp1[i-1]
 * ��ʼ״̬:
 *    dp0[i] = -prices[i]
 *    dp1[i] = 0
 * ���״̬��
 *    answer = max(dp0[n-1], dp1[n-1])
 *
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷȣ�O(n)
 */
int maxProfitII_Method3(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    vector<int> dp0(n, 0);
    vector<int> dp1(n, 0);

    dp0[0] = -prices[0];
    dp1[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp0[i] = max(dp1[i - 1] - prices[i], dp0[i - 1]);
        dp1[i] = max(dp0[i - 1] + prices[i], dp1[i - 1]);
    }

    int temp = max(dp0[n - 1], dp1[n - 1]);
    return temp >= 0 ? temp : 0;
}


#if 0
int main() {
    vector<int> v = { 4, 3, 2, 1 };
    cout << maxProfitII_Method3(v) << endl;
    return 0;
}
#endif// 