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

// 动态规划：
// 类似最长子数组和问题，只不过此处最大值的取得，要比较
// max[i-1]*nums[i], min[i-1]*nums[i] 和 nums[i] 三者的最大和最小值
// 作为最大值和最小值
int maxProduct(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> maxProdEndHere(nums.begin(), nums.end());
	vector<int> minProdEndHere(nums.begin(), nums.end());

	for (int i = 1; i < n; ++i) {
		if (nums[i] > 0) {
			maxProdEndHere[i] = max(maxProdEndHere[i-1] * nums[i], nums[i]);
			minProdEndHere[i] = min(minProdEndHere[i-1] * nums[i], nums[i]);	
		} else if (nums[i] < 0) {
			maxProdEndHere[i] = max(minProdEndHere[i-1] * nums[i], nums[i]);
			minProdEndHere[i] = min(maxProdEndHere[i-1] * nums[i], nums[i]);
		} else if (nums[i] == 0) {
			minProdEndHere[i] = maxProdEndHere[i] = 0;
		}
	}

	int ans = maxProdEndHere[0];
	for (int i = 1; i < n; ++i) {
		ans = max(ans, maxProdEndHere[i]);
	}
	return ans; 
}

int main()
{
	int a[] = {-2, 3, -2};
	vector<int> v(a, a + 3);
	cout << maxProduct(v) << endl;
	return 0;
}