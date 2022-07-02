//
//  Leetcode90_子集II.cpp
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


void solveSubsetII(vector<int>& sofar, vector<int>& nums, int idx, int n, bool choose, vector<vector<int>>& globalAns) {
    if (idx == n) {
        globalAns.push_back(sofar);
        return;
    }
    
    int pivot = nums[idx];
    // 核心要点：如果前面已经选择了，这次需要在执行不选择，因为会重复
    if (idx >= 1 && nums[idx] == nums[idx-1] && choose) {
        // not do choice1
    } else {
        // choice 1: not add to sofar
        solveSubsetII(sofar, nums, idx + 1, n, false, globalAns);
    }
    
    // choice 2: add to sofar
    sofar.push_back(pivot);
    solveSubsetII(sofar, nums, idx + 1, n, true, globalAns);
    sofar.pop_back();

}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = (int) nums.size();
    vector<int> sofar;
    vector<vector<int>> ans;
    solveSubsetII(sofar, nums, 0, n, false, ans);
    return ans;
}


int main() {
    vector<int> nums = { 1, 2, 2 };
    vector<vector<int>> ans = subsetsWithDup(nums);
    
    cout << "ans: " << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
