#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

/**
 * Method1: 使用前缀数组，时间复杂度 O(n^2)，空间复杂度 O(n)
 *          该方法会出现超时TLE，需要优化时间复杂度
 */
int shortestSubarray_Method1(vector<int>& nums, int k) {
    if (nums.empty()) return -1;

    int n = (int)nums.size();
    vector<int> prefix(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + nums[i];

    int minDiff = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int curSum = prefix[j] - prefix[i] + nums[i];
            if (curSum >= k) {
                minDiff = min(minDiff, j - i + 1);
            }
        }
    }

    return minDiff == INT_MAX ? -1 : minDiff;
}


// 方法二：是典型的单调队列问题，花了很长时间去理解这个精巧的solution
//        时间复杂度:O(n)，空间复杂度:O(n)
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int ans = INT_MAX;
    deque<int> Q;
    for (int j = 0;j <= n; ++j) {
        // 如果元素j和队首元素i的区间已经满足要求，则j+1之后的必然满足且区间更大(更差)
        // 所以没必要判断后续的j+1，直接判断i+1开始的元素即可
        while (!Q.empty() && prefix[j] - prefix[Q.front()] >= k) {
            ans = min(ans, j - Q.front());
            Q.pop_front();
        }

        // 如果j和队尾相比更小的话，那么后续以i和j开头如果满足要求，则必然会选择j，因为i
        // 开始的话，区间更大(更差)；所以没必要再判断以i开头的区间是否满足要求
        while (!Q.empty() && prefix[j] < prefix[Q.back()]) {
            Q.pop_back();
        }
        
        Q.push_back(j);
    }
    return ans == INT_MAX ? -1 : ans;
}