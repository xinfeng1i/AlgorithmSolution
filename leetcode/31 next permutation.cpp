#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    
    int n = nums.size();
    int last = n - 1;
    int i;
    while (true) {
        i = last;
        last -= 1;
        if (nums[last] < nums[i]) {
            int j = n - 1;
            while (!(nums[last] < nums[j])) j--;
            swap(nums[last], nums[j]);
            reverse(nums.begin() + i, nums.end());
            return;
        }
        if (last == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
    }
    
}

// more elegant solution
// 1. start from the last position, find the first index such that
//    nums[index-1] < nums[index], so the number in nums[index...n-1]
//    is sorted reversely
// 2. To find the next minimum permutation, we have to swap elems at
//    different position, the position must not lay in [index...n-1] as
//    they already sorted reversely, so we want to swap the index [index-1]
//    swap it with the smallest number in [index...n-1] that is larger than
//    nums[index-1]
// 3. the last step is make the remaining high positions as small as possible
//    we have to sort the numbers in [index...n-1] reversely
void nextPermutation2(vector<int>& nums) {
	int n = nums.size();
	if (n <= 1) return;
	
	int index = n - 1;
	while (index - 1 >= 0 && nums[index - 1] >= nums[index]) {
		index--;
	}
	
	// the nums already sorted reversely, reverse it back
	if (index < 1) {
		reverse(nums.begin(), nums.end());
		return;
	}
	
	// otherwise, we have find the adjacent pair nums[index-1] < nums[index]
	int j = n - 1;
	while (nums[j] <= nums[index - 1]) {
		j--;
	}
	
	swap(nums[index - 1], nums[j]);
	reverse(nums.begin() + index, nums.end());
	return;
}


void PrintVec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    
    nextPermutation2(v);
    
    PrintVec(v);
    
    return 0;
}
