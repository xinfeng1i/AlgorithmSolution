#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = (int)prices.size();
	if (n <= 1) return 0;

	int max_profit = 0;
	int min_price = prices[0];
	for (int i = 1; i < n; ++i) {
		max_profit = max(max_profit, prices[i]-min_price);
		min_price = min(min_price, prices[i]);
	}
	return max_profit;
}