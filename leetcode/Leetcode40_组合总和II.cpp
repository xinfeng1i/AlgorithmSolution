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


void solveCombineSumII(vector<int>& sofar, vector<int>& nums, vector<bool>& visited, int target, int idx, int n, vector<vector<int>>& globalAns) {
    if (target == 0) {
        globalAns.push_back(sofar);
        return;
    }

    int i = idx;
    while (i < n) {
        int elem = nums[i];
        if (!visited[i] && nums[i] <= target) {
            sofar.push_back(nums[i]);
            visited[i] = true;
            solveCombineSumII(sofar, nums, visited, target - nums[i], i + 1, n, globalAns);
            sofar.pop_back();
            visited[i] = false;
        }
        int j = i + 1;
        while (j < n && nums[j] == elem) j++;
        i = j;
    }
}


vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = (int)nums.size();
    vector<int> sofar;
    vector<bool> visited(n, false);
    vector<vector<int>> ans;
    solveCombineSumII(sofar, nums, visited, target, 0, n, ans);

    return ans;
}


int main() {
    vector<int> nums = { 10,1,2,7,6,1,5 };
    int target = 8;

    // vector<int> nums = { 2,5,2,1,2 };
    // int target = 5;

    cout << "ans: " << endl;
    vector<vector<int>> ans = combinationSum2(nums, target);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}