#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int searchRecursive(vector<int>& nums, int left, int right, int target) {
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    //cout << "mid: " << mid << endl;
    
    // found it
    if (nums[mid] == target) return mid;
       
    // not rotated at all
    if (nums[left] <= nums[right]) {
        if (target > nums[mid]) 
            return searchRecursive(nums, mid+1, right, target);
        else if (target < nums[mid])
            return searchRecursive(nums, left, mid-1, target);        
    } else if (nums[mid] <= nums[right] && nums[right] <= nums[left]) {
        // in the right branch
        if (target < nums[mid]) 
            return searchRecursive(nums, left, mid-1, target);
        else if (target > nums[mid]) {
            int leftAns = searchRecursive(nums, left, mid-1, target);
            int rightAns = searchRecursive(nums, mid+1, right, target);
            
            if (leftAns != -1) return leftAns;
            if (rightAns != -1) return rightAns;
            return -1;
            
        }
        
    } else if (nums[mid] >= nums[left] && nums[left] >= nums[right]) {
        // in the left branch
        if (target > nums[mid]) 
            return searchRecursive(nums, mid+1, right, target);
        else if (target < nums[mid]) {
            int leftAns = searchRecursive(nums, left, mid-1, target);
            int rightAns = searchRecursive(nums, mid+1, right, target);
            
            if (leftAns != -1) return leftAns;
            if (rightAns != -1) return rightAns;
            return -1;
            
        }
    }
    
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    return searchRecursive(nums, 0, n-1, target);
}

int main()
{
    int a[] = {3, 1, 2};
    vector<int> nums(a, a + 3);
    cout << search(nums, 1) << endl;
    return 0;
}
