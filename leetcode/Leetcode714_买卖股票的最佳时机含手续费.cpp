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


// 该题与不限制交易次数的题目一样，唯一的区别在于卖出获得利润时需要减去费用fee即可。
int maxProfit(vector<int>& prices, int fee) {
    if (prices.size() <= 1) return 0;

    int n = (int)prices.size();
    vector<long long> dp0(n + 1, 0);
    vector<long long> dp1(n + 1, 0);

    dp1[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i - 1] - fee);
        dp1[i] = max(dp1[i - 1], dp0[i - 1] - prices[i - 1]);
    }

    return max(dp0[n], dp1[n]);
}


int main() {
    vector<int> v = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    int ans = maxProfit(v, fee);
    cout << ans << endl;

    vector<int> v2 = { 1,3,7,5,10,3 };
    int fee2 = 3;
    int ans2 = maxProfit(v2, fee2);
    cout << ans2 << endl;

    return 0;
}