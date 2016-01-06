#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0;
    int high = int(nums.size()) - 1;
    // Loop Invariant: 1. low < high
    //                 2. mid != high and thus nums[mid] != nums[high]
    //                 3. minimum is between [low, high]
    // Loop will exit: after very loop, either high will decrese or low
    //                 will increase, so the interval [low, high] will
    //                 always shrink
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[high]) {
            high = mid;
        } else if (nums[mid] > nums[high]) {
            low = mid + 1;
        }
    }
    return nums[low];
}