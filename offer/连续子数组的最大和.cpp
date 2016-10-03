#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 定义f[i]表示以第i个元素结尾的最大连续子数组和
 * 则 f[i+1] = max(f[i] + A[i+1], A[i+1])
 */

int FindGreatestSumOfSubArray(vector<int> A) {
	if (A.empty()) return 0;
	
	int n = static_cast<int>(A.size());
	vector<int> f(n, 0);
	f[0] = A[0];
	for (int i = 1; i < n; ++i) {
		f[i] = max(f[i-1] + A[i], A[i]);
	}
	
	int ans = f[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, f[i]);
	}
	return ans;
}

int main()
{
	vector<int> v = {6,-3,-2,7,-15,1,2,2};
	cout << FindGreatestSumOfSubArray(v) << endl;
	return 0;
}
