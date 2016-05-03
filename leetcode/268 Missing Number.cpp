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


// 解法一：
// 做差法，计算数组和，用总和-数组和
#if 0
int missingNumber(vector<int>& nums) {
	long long sum = 0;
	for (size_t i = 0; i < nums.size(); ++i) {
		sum += nums[i];
	}

	int n = nums.size();
	long long temp = (long long)(n+1) * (long long)n / 2;

	return temp - sum;
}
#endif //0

// 解法二
// 1. 从左到右扫描每一个数字，对于[0, n-1]之间的元素，将其递归的放置到正确的位置
// 2. 第二遍扫描，位置i的元素nums[i]应该等于i；否则，则缺少元素i
// 3. 如果第二遍扫描完后，全部元素都在正确的位置，则必然缺少元素n
int missingNumber(vector<int>& nums) {
	int n = (int)nums.size();

	for (int i = 0; i < n; ++i) {
		int target = nums[i];
		while (target >= 0 && target < n && target != nums[target]) {
			int new_target = nums[target];
			nums[target] = target;
			target = new_target;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i != nums[i]) {
			return i;
		}
	}
	return n;
}

// Test
#if 0
int main()
{
	int a[] = {0, 1, 2};
	vector<int> v(a, a + 3);
	cout << missingNumber(v) << endl;
	return 0;
}
#endif //