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

// 前缀数组、后缀数组算法
// 利用输出进行两趟遍历，从而得到结果，避免O(n)的空间复杂度
// 此算法时间复杂度为O(n)，空间复杂度为O(1)
vector<int> productExceptSelf(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> output(nums.begin(), nums.end());
	
	// output[i]存放nums[0]*nums[1]*...*nums[i-1]
	int f = 1; // 从前至后的累积
	for (size_t i = 0; i < nums.size(); ++i) {
		if (i == 0) {
			output[i] = 1;
		} else {
			output[i] = f * nums[i-1];
			f *= nums[i-1];
		}
	}

	// 首先计算[i]位置之后的累积nums[n-1]*nums[n-2]...*nums[i+1]
	int b = 1; // 从后之前的累积
	for (int j = n - 1; j >= 0; --j) {
		if (j == n - 1) {
			output[j] *= b;
		} else {
			output[j] *= b * nums[j+1];
			b *= nums[j+1];
		}
	}

	return output;
}

#if 0
int main()
{
	int a[] = {1, 2, 3, 4};
	vector<int> v(a, a + 4);
	vector<int> ans = productExceptSelf(v);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}
#endif //0