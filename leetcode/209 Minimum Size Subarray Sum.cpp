#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

// Method 1: 计算累积和数组，然后采用二分搜索，复杂度O(nlogn)
int minSubArrayLen(int s, vector<int>& A) {
	if (A.empty()) return 0;
	
	int n = (int)A.size();
	vector<int> sum(n, 0);
	sum[0] = A[0];
	for (int i = 0; i < n; ++i) {
		sum[i] = sum[i-1] + A[i];
	}
	
	vector<int>::iterator it = lower_bound(sum.begin(), sum.end(), s);
	int min_len = n;
	if (it != sum.end()) min_len = (it - sum.begin()) + 1;
	else min_len = 0;
	for (int i = 0; i < n; ++i) {
		int x = sum[i];
		it = lower_bound(sum.begin()+i+1, sum.end(), x + s);
		if (it == sum.end()) {
			break;
		} else {
			int j = it - sum.begin();
			min_len = min(min_len, j-i);
		}
	}
	return min_len;
}

// Method 2: 利用双指针，时间复杂度O(n)
int minSubArrayLen(int s, vector<int>& A) {
	if (A.empty()) return 0;
	
	int n = (int)A.size();
	int left = 0, right = 0;
	int sum = 0;
	int min_len = n + 1;
	while (right < n) {
		while (right < n && sum < s) {
			sum += A[right];
			right++;
		}
		
		if (sum < s) break;
		
		// sum >= s
		min_len = min(min_len, right-left);
		
		while (sum >= s) {
			sum -= A[left];
			left++;
		}
		
		// sum < s
		min_len = min(min_len, right-left+1);
	}
	
	if (min_len == n+1) min_len = 0;
	return min_len;
}


