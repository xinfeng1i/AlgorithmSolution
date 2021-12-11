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
 * 思路：在最低点买，在最高点卖
 * 操作：记录当前位置之前的最低点，计算差值极为当前可得的利润，遍历所有位置得到最大利润值即可
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    int preMin = prices[0];
    int profit = 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] > preMin) {
            profit = max(profit, prices[i] - preMin);
        }
        preMin = min(preMin, prices[i]);
    }

    return profit;
}