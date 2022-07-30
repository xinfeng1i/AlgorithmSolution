//
//  Leetcode698_划分K个相等的子集.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/29.
//


#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
using namespace std;


/*
 * 经典回溯算法：重要的是剪枝克服超时问题.
 */
bool canPartitionKSet(vector<int>& ksum, vector<int>& nums, int idx, int k, int n, int avg) {
    if (idx == n) {
        return true;
    }
    
    // choice: select from the k bucket
    for (int i = 0; i < k; ++i) {
        // 剪枝1: 对于第0个元素，只需要判断其放在第一个bucket的情况
        if (idx == 0 && i >= 1) break;
        
        // 剪枝2：如果当前bucket和与前一个一样，则不需要进一步判断了
        if (i >= 1 && ksum[i] == ksum[i-1]) continue;
        
        // 剪枝3: 如果前判断，只需要放入可能放入且不溢出的bucket
        if (ksum[i] + nums[idx] <= avg) {
            // put this elements
            ksum[i] += nums[idx];
            // check recursively
            bool ok = canPartitionKSet(ksum, nums, idx + 1, k, n, avg);
            if (ok) {
                return true;
            } else {
                // trackbacking
                ksum[i] -= nums[idx];
            }
        }
    }
    return false;
}


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int tot = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        tot += nums[i];
    }
    if (tot % k != 0) return false;
    int avg = tot / k;
    
    // 剪枝4:降序排列，增加剪枝的命中概率
    sort(nums.begin(), nums.end(), greater<int>());
    
    int n = (int) nums.size();
    
    vector<int> kset(k, 0);
    vector<int> ksum(k, 0);
    
    return canPartitionKSet(ksum, nums, 0, k, n, avg);
}


int main() {
    vector<int> cur;
    //vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    //int k = 4;
    
    //vector<int> nums = { 3, 2, 1 };
    //int k = 3;
    
    // vector<int> nums = { 815,625,3889,4471,60,494,944,1118,4623,497,771,679,1240,202,601,883 };
    // int k = 3;
    
    // vector<int> nums = { 114,96,18,190,207,111,73,471,99,20,1037,700,295,101,39,649 };
    // int k = 4;
    
    //vector<int> nums = { 3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269 };
    //int k = 5;
    
    //vector<int> nums = { 1, 2, 3, 4 };
    //int k = 2;
    
    vector<int> nums = { 10,5,5,4,3,6,6,7,6,8,6,3,4,5,3,7 };
    int k = 8;
    
    clock_t begin = clock();
    
    bool ans = canPartitionKSubsets(nums, k);
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    cout << "ans = " << ans << endl;
    cout << "time cost: " << elapsed_secs << endl;
    
    
    return 0;
}
