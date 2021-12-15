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
 * ״̬���壺dp[amount]��ʾ�ճ�amount��Ҫ������Ӳ��
 * ״̬ת�ƣ�dp[amount] = dp[amount-some_coin] + 1 for all some_coin
 * ��ʼ״̬��dp[some_coin] = 1
 * ע�⣺�߽���������ʼ��ʱ��some_coin���ܻ����amount���¶�ջ���
 * ʱ�临�Ӷȣ�O(amount * n)
 * �ռ临�Ӷȣ�O(amount)
 */
int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (coins.empty()) return -1;

    int n = (int)coins.size();
    vector<int> dp(amount + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (coins[i] <= amount) {
            dp[coins[i]] = 1;
        }
    }

    for (int i = 1; i <= amount; ++i) {
        if (dp[i] != 0) continue;
        bool found = false;
        int minNum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            int coin = coins[j];
            if (i >= coin && dp[i-coin] >= 0) {
                found = true;
                minNum = min(dp[i - coin] + 1, minNum);
            }
        }

        if (found) dp[i] = minNum;
        else dp[i] = -1;
    }

    for (int i = 1; i <= amount; ++i) {
        cout << i << ": " << dp[i] << endl;
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {2};
    int amount = 1;
    cout << coinChange(coins, amount) << endl;
    return 0;
}