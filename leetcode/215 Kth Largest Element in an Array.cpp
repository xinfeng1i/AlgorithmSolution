#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int partitionVector(vector<int>& nums, int left, int right)
{
	assert(left <= right);
	int pivot = nums[right];
	int i = left - 1;
	int j = right;
	for (j = left; j < right; ++j)
	{
		if (nums[j] >= pivot)
		{
			i += 1;
			swap(nums[i], nums[j]);
		}
	}
	
	swap(nums[i+1], nums[right]);
	return (i + 1);
}

int findKthLargestUtil(vector<int>& nums, int left, int right, int k)
{
    // partition middle is not equal to rank
	int mid = partitionVector(nums, left, right);
	
	// current rank in [left, right] is (mid - left + 1) 
	int rank = mid - left + 1;
	if (rank == k) 
	{
		return nums[mid];
	}
	else if (rank > k)
	{    // need find kth largest in [left, mid - 1]
		return findKthLargestUtil(nums, left, mid - 1, k);	
	}
	else
	{   // need find (k - rank)th largest in [mid + 1, right]
		return findKthLargestUtil(nums, mid + 1, right, k - rank);
	}
	
}

int findKthLargest(vector<int>& nums, int k)
{
	assert(k <= nums.size());
	int n = nums.size();
	return findKthLargestUtil(nums, 0, n - 1, k);
}

int main()
{
	int a[] = {-1, 2, 0};
	vector<int> nums(a, a + 3);
	cout << findKthLargest(nums, 3) << endl;
	return 0;
}
