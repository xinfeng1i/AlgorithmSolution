#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


/*
 * Classic N-Sum problem
 * Method1: Naive for-loop, O(n^3)
 * Method2: Sorting + two pointer, O(n^2). Elegant solution.
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = (int)nums.size();

    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
        // Notice: skip the duplicate first number
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        int a = nums[i];
        int target = 0 - a;
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi) {
            int b = nums[lo];
            int c = nums[hi];
            if (b + c < target) {
                lo++;
            }
            else if (b + c > target) {
                hi--;
            }
            else {
                vector<int> temp(3, 0);
                temp[0] = a;
                temp[1] = b;
                temp[2] = c;
                result.push_back(temp);
                while (lo < n && nums[lo] == b) lo++;  // Notice Index Overflow
                while (hi >= 0 && nums[hi] == c) hi--; // Notice Index Overflow
            }
        }
    }
    return result;
}


int main() {
    vector<int> v = { 0, 0, 0 };
    vector<vector<int>> result = threeSum(v);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << " " << result[i][j];
        }
        cout << endl;
    }
    return 0;
}