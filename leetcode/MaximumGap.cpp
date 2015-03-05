#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
using namespace std;


int maximumGap(vector<int>& num)
{
	size_t n = num.size();
	if (n < 2) return 0;

	// using as ordered_hash
	map<int, int> cnt;
	for (size_t i = 0; i < n; ++i)
	{
		cnt[ num[i] ]++;
	}

	int ans = 0;
	for (auto it = cnt.begin(); it != cnt.end(); ++it)
	{
		auto next = it; next++;
		if (next == cnt.end()) break;
		int tmp = next->first - it->first;
		if (tmp > ans) ans = tmp;
	}

	return ans;
}

// Method 2: bucket sorting
// the largest gap between the two adjacent elements no smaller than
// gap = (max - min) / (n - 1);
// the k-th bucket contains elements in [min + k*gap, min + (k+1) *gap)
int maximumGap2(vector<int>& num)
{
	// special case
	int n = num.size();
	if (n < 2) return 0;

	// compute gap
	int minVal = *min_element(num.begin(), num.end());
	int maxVal = *max_element(num.begin(), num.end());
	int gap = ceil(double(maxVal - minVal) / (n - 1));
	
	// construct buckets
	int bucketSize = ceil(double(maxVal - minVal) / gap);
	vector<int> bucketMin(bucketSize, INT_MAX);
	vector<int> bucketMax(bucketSize, INT_MIN); 

	// put elems into buckets
	for (int i = 0; i < n; ++i)
	{
		// skip min & max vals
		if (num[i] == minVal || num[i] == maxVal) continue;
		int id = (num[i] - minVal) / gap;
		bucketMin[id] = min(bucketMin[id], num[i]);
		bucketMax[id] = max(bucketMax[id], num[i]);
	}

	int ans = 0;
	int pre = minVal;
	for (int i = 0; i < bucketSize; ++i)
	{
		// empty bucket
		if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue;
		ans = max(ans, bucketMin[i] - pre);
		pre = bucketMax[i];
	}
	ans = max(ans, maxVal - pre);

	return ans;
}

int main()
{
	return 0;
}
