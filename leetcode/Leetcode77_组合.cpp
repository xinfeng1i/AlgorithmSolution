//
//  Leetcode77_组合.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/5.
//


#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

void solveCombine(vector<int>& sofar, vector<int>& nums, vector<bool>& visited, int n, int k, int idx, vector<vector<int>>& globalAns) {
    if (sofar.size() == k) {
        globalAns.push_back(sofar);
        return;
    }
    
    // 注意：如果枚举时从0开始，会造成重复，例如 1,2 和 2,1
    // 指定从 idx 开始，后续的枚举从 idx + 1 开始可以避免这种重复
    for (int i = idx; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            sofar.push_back(nums[i]);
            solveCombine(sofar, nums, visited, n, k, i + 1, globalAns);
            visited[i] = false;
            sofar.pop_back();
        }
    }
}


vector<vector<int>> combine(int n, int k) {
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    vector<bool> visited(n, false);
    vector<int> sofar;
    
    vector<vector<int>> ans;
    solveCombine(sofar, nums, visited, n, k, 0, ans);
    
    return ans;
}


int main() {
    int n = 6;
    int k = 2;
    
    vector<vector<int>> ans = combine(n, k);
    cout << "ans size: " << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
