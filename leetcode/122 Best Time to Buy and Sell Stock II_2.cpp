#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n <= 1) return 0;
	
	int ans = 0;
	int peak = prices[0];
	int valley = prices[0];
	int i = 0;
	while (i < n) {
		while (i < n-1 && prices[i] > prices[i+1]) i++;
		valley = prices[i];
		while (i < n-1 && prices[i] < prices[i+1]) i++;
		peak = prices[i];
		
		if (peak > valley) {
			ans += peak - valley;
		}
		i += 1;
	}
	
	return ans;
}

/*
 * 只需要考虑单调增区间[a, d]的利润
 * d-a = (d-c)+(c-b)+(b-a)
 * 因此只需要对所有的正diff做累加即可
 */
int maxProfit(vector<int>& prices) {
	int n = prices.size ();
	if (n <= 1) return 0;
	
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += max(0, prices[i]-prices[i-1]);
	}
	return ans;
}

int main() {
	int a[] = {3, 5, 1, 7, 9};
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a+n);
	cout << maxProfit(v) << endl;
	cout << maxProfit2(v) << endl;
	return 0;
	
}
