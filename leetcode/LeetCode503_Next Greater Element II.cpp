#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <deque>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


// 使用单调stack
// Time: O(n)
// Space: O(n)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> ans(n, -1);

    stack<int> S;
    int i = 0;
    int cnt = 0;
    while (true) {
        while (!S.empty() && nums[S.top()] < nums[i]) {
            int idx = S.top(); S.pop();
            if (ans[idx] == -1) ans[idx] = nums[i];
        }

        S.push(i);
        i = (i + 1) % n;
        cnt += 1;
        if (cnt >= 2 * n + 1) break;
    }
    return ans;
}