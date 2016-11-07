#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVec(const vector<int>& v) {
	for (int x:v) {
		cout << " " << x;
	}
	cout << endl;
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n <= 1) return 0;
	vector<int> buy(n+1, 0);
	vector<int> sell(n+1, 0);
	vector<int> rest(n+1, 0);
	
	buy[0] = -prices[0];
	sell[0] = 0;
	rest[0] = 0;
	
	for (int i = 1; i < n; ++i) {
		int p = prices[i];
		buy[i] = max(buy[i-1], rest[i-1]-p);
		sell[i] = max(sell[i-1], buy[i-1]+p);
		rest[i] = max(buy[i-1], max(sell[i-1], rest[i-1]));
	}
	//PrintVec(buy);
	//PrintVec(sell);
	//PrintVec(rest);
	return max(buy[n-1], max(sell[n-1], rest[n-1]));
}

int main()
{
	int a[] = {1, 2, 3, 0, 2};
	vector<int> v(a, a+5);
	cout << maxProfit(v) << endl;
	return 0;
}
