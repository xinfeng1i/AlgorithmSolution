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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

int CountAndMergeHelper(vector<long long>& sum, int left, int right, int lower, int upper) {
	// base case
	if (left >  right) return 0;
	if (left == right) return (lower <= sum[left] && sum[left] <= upper) ? 1 : 0; 

	// compute the two sub-problems
	int mid = left + (right - left) / 2;
	int cnt1 = CountAndMergeHelper(sum, left, mid, lower, upper);
	int cnt2 = CountAndMergeHelper(sum, mid+1, right, lower, upper);

	// As the two sub-problems have been solved, we have two halves [left, mid]
	// and [mid+1, right] has been sorted in accending order, then for each element
	// in the left half, we can find the in O(n) time averagely,as both j and k
	// will always increases during the outer loop
	int cnt3 = 0;
	int j = mid + 1; 
	int k = mid + 1;
	for (int i = left; i <= mid; ++i) {
		while (j <= right && sum[j] - sum[i] < lower) j++;
		while (k <= right && sum[k] - sum[i] <= upper) k++;
		cnt3 += k - j;
	}
	// merge the two sorted halves
	inplace_merge(sum.begin()+left, sum.begin()+mid+1, sum.begin()+right+1);
	return cnt1 + cnt2 + cnt3;
}

int countRangeSum(vector<int>& A, int lower, int upper) {
	int n = (int) A.size();
	vector<long long> sum(n+1, 0LL);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + A[i-1];
	}
	return CountAndMergeHelper(sum, 1, n, lower, upper);
}