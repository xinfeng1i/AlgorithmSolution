#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
	int n = (int)nums.size();

	// 从左到右逐一遍历整个数组，如果遇到负数和0直接忽略；
	// 否则，将整数k放置在正确的第k-1个位置；然后递归的放置第k-1位置的整数
	for (int i = 0; i < n; ++i) {
		int target = nums[i];
		while (0 < target && target <= n && target != nums[target-1]) {
			int new_target = nums[target-1];
			nums[target-1] = target;
			target = new_target;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] != i+1) {
			return i+1;
		}
	}

	return n+1;
}

#if 0
int main()
{
	int a[] = {2, 1};
	vector<int> v(a, a+2);
	cout << firstMissingPositive(v) << endl;
	return 0;
}
#endif //0