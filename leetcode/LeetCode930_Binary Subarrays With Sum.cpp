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


int numSubarraysWithSum(vector<int>& nums, int goal) {
    // 0 0 1 0 1 0 0 0 1

    int n = (int)nums.size();
    if (goal == 0) {
        int k = 0;
        int cnt = 0;
        int ans = 0;

        while (k < n) {
            while (k < n && nums[k] == 0) { cnt++; k++; }
            // cout << "cnt = " << cnt << endl;
            ans += cnt * (cnt + 1) / 2;
            if (k >= n) break;
            while (k < n && nums[k] == 1) k++;
            cnt = 0;
        }
        return ans;
    }


    int i = 0;
    int j = 0;
    int cnt = 0;
    int ans = 0;
    while (j < n) {
        while (j < n && cnt < goal) {
            cnt += nums[j];
            j++;
        }

        if (j >= n && cnt < goal) break;

        int prefix = 0;
        while (cnt == goal && nums[i] == 0) {
            prefix++;
            i++;
        }
        ans += prefix + 1;

        while (j < n && nums[j] == 0) {
            ans += prefix + 1;
            j++;
        }

        cnt -= nums[i];
        i++;

    }
    return ans;
}

