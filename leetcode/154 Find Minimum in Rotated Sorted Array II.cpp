#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// binary search, worst case: O(n)
// Loop Invariant:
// 1. low < high
// 2. mid < high so high = mid, will shrink the interval
// 3. minimum elements in [low, high]
// Loop Exit:
// In each iteration, the interval [low, high] will always
// shrink, so the loop must exit
int findMin(vector<int>& nums) {
    int low = 0;
    int high = int(nums.size()) - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high]) {
            high = mid;
        } else if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else if (nums[mid] == nums[high]) {
            // have no idea, mid in which side
            high--;
        }
    }
    return nums[low];
}