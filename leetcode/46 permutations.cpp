#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    return permutation(nums, 0, n - 1);
}

vector<vector<int>> permutation(vector<int>& nums, int left, int right) {
    vector<vector<int>> ans;
    if (left > right) return ans;
    
    for (int i = left; i <= right; ++i) {
        swap(nums[i], nums[left]);
        
        vector<vector<int>> temp = permutation(nums, left + 1, right);
        
        if (temp.empty()) {
            vector<int> cur;
            cur.push_back(nums[left]);
            ans.push_back(cur);
        } else {
            for (size_t i = 0; i < temp.size(); ++i) {
                vector<int> cur;
                cur.push_back(nums[left]);
                for (size_t j = 0; j < temp[i].size(); ++j) {
                    cur.push_back(temp[i][j]);
                }
                ans.push_back(cur);
            }           
        }
        
        swap(nums[i], nums[left]);
    }
    return ans;
}


// solution 2: backtracking
void permutateRecursive(vector<int>& nums, int start, vector<vector<int> >& result)
{
    // base case;
    if (start >= nums.size()) {
        result.push_back(nums);
		//PrintVec(nums);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]);
        permutateRecursive(nums, start + 1, result);
        // reset
        swap(nums[start], nums[i]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > result;
    permutateRecursive(nums, 0, result);
    return result;
}

