//
//  Leetcode46_全排列.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/1.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;


void quanpailie(vector<int>& nums, int left, int right, vector<vector<int>>& globalAns) {
    // Base Case
    if (left > right) {
        globalAns.push_back(nums);
        return;
    }
    
    for (int i = left; i <= right; ++i) {
        // 1. try a choice
        swap(nums[i], nums[left]);
        // 2. recursive
        quanpailie(nums, left + 1, right, globalAns);
        // 3. backtrack
        swap(nums[i], nums[left]);
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    int n = (int) nums.size();
    vector<vector<int>> ans;
    quanpailie(nums, 0, n-1, ans);
    return ans;
}


#if 0
int main() {
    vector<int> v = { 1, 2, 3 };
    vector<vector<int>> result = permute(v);
    
    for (size_t i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << " " << result[i][j];
        }
        cout << endl;
    }
    return 0;
}
#endif // 0
