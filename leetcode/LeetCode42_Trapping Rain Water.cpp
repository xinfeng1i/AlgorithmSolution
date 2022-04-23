#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

// Method1: 
//    pre-calculate the left & right bound for each element
//    time: O(n)
//    space: O(n)
int trap_method1(vector<int>& height) {
    if (height.empty() || height.size() <= 2) return 0;

    int n = (int) height.size();

    // get the left bound height
    vector<int> maxLeft = vector<int>(n, 0);
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
    }

    // get the right bound height
    vector<int> maxRight = vector<int>(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        maxRight[i] = max(maxRight[i + 1], height[i + 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int h = min(maxLeft[i], maxRight[i]);
        if (height[i] < h) {
            ans += h - height[i];
        }
    }

    return ans; 
}


// Method2:
//   Mono-stack, find the left & right first larger number
//   time: O(n)
//   space: O(n)
int trap_method2(vector<int>& height) {
    if (height.empty() || height.size() <= 2) return 0;

    int n = (int)height.size();
    int ans = 0;

    // mono-stack: store the index of height
    stack<int> S;
    for (int i = 0; i < n; ++i) {
        if (S.empty() || height[i] <= height[S.top()]) {
            S.push(i);
            continue;
        }

        while (!S.empty() && height[i] > height[S.top()]) {
            int curIndex = S.top(); S.pop();
            if (!S.empty()) {
                int preIndex = S.top();
                int w = i - preIndex - 1;
                int h = min(height[preIndex], height[i]) - height[curIndex];
                ans += w * h;
            }
        }
        S.push(i);
    }
    return ans;
}



// Method3:
//   find the minbound from left or right
//   time: O(n)
//   space: O(1)
int trap(vector<int>& height) {
    if (height.empty() || height.size() <= 2) return 0;

    int n = (int)height.size();
    int ans = 0;

    int lo = 0;
    int hi = n - 1;
    int minBound = 0;
    while (lo < hi) {
        if (height[lo] < height[hi]) {
            if (height[lo] < minBound) ans += minBound - height[lo];
            minBound = max(minBound, height[lo]);
            lo++;
        }
        else {
            if (height[hi] < minBound) ans += minBound - height[hi];
            minBound = max(minBound, height[hi]);
            hi--;
        }
    }

    return ans;
}


int main() {
    vector<int> v1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    vector<int> v2 = { 4,2,0,3,2,5 };
    cout << trap(v1) << endl;
    cout << trap(v2) << endl;
    return 0;
}