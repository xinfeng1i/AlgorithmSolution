#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


void solveCombineSum(vector<int>& sofar, vector<int>& nums, int target, int idx, vector<vector<int>>& globalAns) {
    if (target == 0) {
        globalAns.push_back(sofar);
        return;
    }

    for (int i = idx; i < (int) nums.size(); ++i) {
        int x = nums[i];
        if (x <= target) {
            sofar.push_back(x);
            solveCombineSum(sofar, nums, target - x, i, globalAns);
            sofar.pop_back();
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<int> sofar;
    vector<vector<int>> ans;
    solveCombineSum(sofar, nums, target, 0, ans);
    return ans;
}


int main() {
    vector<int> nums = { 2, 3, 5 };
    int target = 8;

    cout << "ans: " << endl;
    vector<vector<int>> ans = combinationSum(nums, target);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}