#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findPeakElementRecursive(vector<int>& nums, int left, int right);
int findPeakElementRecursive2(vector<int>& nums, int left, int right);

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    return findPeakElementRecursive2(nums, 0, n - 1);
}

int findPeakElementRecursive(vector<int>& nums, int left, int right) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    if (mid == left && mid == right) {
        return mid;
    } else if (mid != left && mid != right) {
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) {
            int leftidx = findPeakElementRecursive(nums, mid + 1, right);
            if (leftidx != -1) return leftidx;
            int rightidx = findPeakElementRecursive(nums, left, mid - 2);
            return rightidx;
        } else if (nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]) {
            int leftidx = findPeakElementRecursive(nums, left, mid - 1);
            if (leftidx != -1) return leftidx;
            int rightidx = findPeakElementRecursive(nums, mid + 2, right);
            return rightidx;
        } else if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]) {
            int leftidx = findPeakElementRecursive(nums, left, mid - 1);
            if (leftidx != -1) return leftidx;
            int rightidx = findPeakElementRecursive(nums, mid + 1, right);
            return rightidx;
        }
    } else if (mid == left) {
        if (nums[mid] > nums[mid+1]) {
            return mid;
        } else {
            return findPeakElementRecursive(nums, mid+1, right);
        }
        
    } else if (mid == right) {
        if (nums[mid-1] < nums[mid]) {
            return mid;
        } else {
            return findPeakElementRecursive(nums, left, mid-1);
        }  
    }
}

// a more elegant solution from discussion on leetcode
// as nums[i] != nums[i-1], so there are only four case:
// 1. nums[i-1] < nums[i] && nums[i] > nums[i+1], then nums[i] is peak
// 2. nums[i-1] < nums[i] && nums[i] < nums[i+1], then [i+1...n-1] must contain a peak
// 3. nums[i-1] > nums[i] && nums[i] > nums[i+1], then [0...i-1] must contain a peak
// 4. nums[i-1] > nums[i] && nums[i] < nums[i+1], then either side must have peaks

int findPeakElementRecursive2(vector<int>& nums, int left, int right) {
	if (left == right) { // only has one element
		return left;
	} else if (left + 1 == right) { // only has two element
		if (nums[left] > nums[right]) return left;
		else return right;
	} else {
		int mid = left + (right - left) / 2;
		if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
			return mid;
		} else if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) {
			return findPeakElementRecursive(nums, mid+1, right);
		} else {
            return findPeakElementRecursive(nums, left, mid-1);
        }
	}
}

int main()
{
    int a[] = {1, 2, 3, 1};
    vector<int> v(a, a + 4);
    cout << findPeakElement(v) << endl;
    return 0;
}
