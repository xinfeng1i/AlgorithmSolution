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


// 仅允许交易一次，则最大利润必然是在最低点买入，最高点卖出
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int minValSoFar = prices[0];
    int profit = 0;
    int n = (int)prices.size();
    for (int i = 1; i < n; ++i) {
        if (prices[i] > minValSoFar) {
            profit = max(profit, prices[i] - minValSoFar);
        }

        minValSoFar = min(minValSoFar, prices[i]);
    }

    return profit;
}


int main() {
    vector<int> v = { 7,1,5,3,6,4 };
    cout << maxProfit(v) << endl;
    return 0;
}