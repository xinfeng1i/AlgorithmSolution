//
//  Leetcode47_全排列II.cpp
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


void quanpailieII(vector<int>& sortedNums, int left, int right, vector<vector<int>>& globalAns) {
    if (left > right) {
        globalAns.push_back(sortedNums);
        return;
    }
    
    // 核心点在于：每个重复的pivot仅需要被交换到left位置一次，因此需要一个seen来记录已经被交换过的pivot
    set<int> seen;
    for (int i = left; i <= right; ++i) {
        int pivot = sortedNums[i];
        if (seen.find(pivot) == seen.end()) {
            swap(sortedNums[left], sortedNums[i]);
            quanpailieII(sortedNums, left + 1, right, globalAns);
            swap(sortedNums[left], sortedNums[i]);
            
            seen.insert(pivot);
        }
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = (int) nums.size();
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> ans;
    quanpailieII(nums, 0, n - 1, ans);
    return ans;
}



int main() {
    vector<int> v = { 0, 0, 0, 1, 9 };
    vector<vector<int>> ans = permuteUnique(v);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
