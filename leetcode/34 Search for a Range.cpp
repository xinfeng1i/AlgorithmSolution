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

vector<int> searchRange(vector<int>& nums, int target) {
	int n = int(nums.size());
	int i = 0;
	int j = n-1;
	while (i < j) {
		int mid = i + (j-i)/2;
		if (nums[mid] < target) {
			i = mid + 1;
		} else {
			j = mid;
		}
	}

	// cannot find target
	if (nums[i] != target) {
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
	}

	// 大于等于target的第一个位置
	int idx1 = i;

	int idx2 = i;
	while (idx2 < n && nums[idx2] == target) idx2++;
	idx2 = idx2-1;

	vector<int> ans;
	ans.push_back(idx1);
	ans.push_back(idx2);
	return ans;
}

int main()
{
	int a[] = {5, 7, 7, 9, 10};
	vector<int> v(a, a+5);
	vector<int> ans = searchRange(v, 7);
	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}