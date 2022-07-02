//
//  Leetcode78_子集.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/2.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

void solveSubset(vector<int>& sofar, vector<int>& nums, int idx, int n, vector<vector<int>>& globalAns) {
    if (idx == n) {
        globalAns.push_back(sofar);
        return;
    }
    
    int pivot = nums[idx];
    // choice 1: not add to sofar
    solveSubset(sofar, nums, idx + 1, n, globalAns);
    
    // choice 2: add to sofar
    sofar.push_back(pivot);
    solveSubset(sofar, nums, idx + 1, n, globalAns);
    sofar.pop_back();
}


vector<vector<int>> subsets(vector<int>& nums) {
    int n = (int) nums.size();
    
    vector<int> sofar;
    vector<vector<int>> ans;
    solveSubset(sofar, nums, 0, n, ans);
    
    return ans;
}


int main() {
    vector<int> nums = { 0 };
    
    vector<vector<int>> ans = subsets(nums);
    
    cout << "ans: " << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
    
};
