#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method: using mono-stack
//    1) for each bar, it can be extend to left and right until encounter to the lower ones
//    2) add a soldier at the end to make sure all the bars can be popped out.
// Time: O(n)
// Space: O(n)
int largestRectangleArea(vector<int>& height) {
    if (height.empty()) return 0;
    
    // as a soldier to make all the heights pop from the stack
    height.push_back(0);
    int n = (int) height.size();
    int ans = 0;
    
    stack<int> S;
    for (int i = 0; i < n; ++i) {
        if (S.empty() || height[i] >= height[S.top()]) {
            S.push(i);
            continue;
        }
        
        while (!S.empty() && height[i] < height[S.top()]) {
            int curIdx = S.top(); S.pop();
            
            int prevIdx = -1;
            if (!S.empty()) prevIdx = S.top();
            
            int w = i - prevIdx - 1;
            int h = height[curIdx];
            ans = max(ans, w * h);
        }
        S.push(i);
    }
    
    // reset the soldier
    height.pop_back();
    return ans;
}


int main() {
    vector<int> v = { 2, 3, 4, 1, 1, 1, 1, 1, 1, 1 };
    cout << largestRectangleArea(v) << endl;
    
    vector<int> v1 = {2,1,5,6,2,3};
    cout << largestRectangleArea(v1) << endl;
    
    vector<int> v2 = {2, 4};
    cout << largestRectangleArea(v2) << endl;
    
    return 0;
}
