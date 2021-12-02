#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/*
 * ������ֲ������⣺ע�������ı߽������ע��mid���ƶ������
 * ʱ�临�Ӷȣ�O(logn)
 */
int lastPosition(vector<int>& nums, int target) {
	if (nums.empty()) return -1;

	int left = 0;
	int right = (int)nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left + 1) / 2;
		if (nums[mid] == target) {
			left = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return nums[left] == target ? left : -1;
}
