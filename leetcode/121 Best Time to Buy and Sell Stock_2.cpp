#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxProfit(vector<int>& price) {
	int n = price.size();
	if (n <= 1) return 0;
	
	int ans = 0;
	// 记录当前碰到的最小元素
	int sofar_min = price[0];
	for (int j = 1; j < n; ++j) {
		// 对于每个股票价格，如果其比最小元素大
        // 该时间点卖出，可以产生利润, 更新结果
		if (price[j] >= sofar_min) {
			ans = max(ans, price[j] - sofar_min);
		}
		// 更新目前碰到的最小元素
		sofar_min = min(sofar_min, price[j]);
	}
	return ans;
}

int main()
{
	//int a[] = {7, 1, 5, 3, 6, 4};
	int a[] = {7, 6, 4, 3, 1};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a+n);
	cout << maxProfit(v) << endl;
	return 0;
}
