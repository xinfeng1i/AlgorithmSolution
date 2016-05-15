#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

// Cycle Detection: slow and fast pointers
int findDuplicate(vector<int>& nums) {
	if (nums.size() <= 1) return false;

	int n = nums.size();
	int slow = 0;
	int fast = 0;

	while (true) {
		slow = nums[slow];
		fast = nums[nums[fast]];
		if (slow == fast) break;
	}

	int finder = 0;
	while (finder != slow) {
		finder = nums[finder];
		slow = nums[slow];
	}
	return slow;
}

int main() {
	int a[] = {1, 3, 4, 2, 1};
	vector<int> v(a, a+5);
	cout << findDuplicate(v) << endl;
	return 0;
}
