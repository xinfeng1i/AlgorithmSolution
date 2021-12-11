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
 * ˼·������͵�������ߵ���
 * ��������¼��ǰλ��֮ǰ����͵㣬�����ֵ��Ϊ��ǰ�ɵõ����󣬱�������λ�õõ��������ֵ����
 *
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷȣ�O(1)
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