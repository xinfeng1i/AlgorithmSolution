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


// 单调stack问题：
// 本质上寻找一个区间[i,j]使得 (j-i+1)*min_height([i,j])最大
// 观察到对于 x1 < x2，如果 h1 > h2，如果存在某个位置y得到最大矩形
// 如果x2可以满足，则必然x1可以满足；所以跳过x2，从而遍历的序列是
// 单调递增训练
// Time: O(n), Space: O(n)
int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;

    // trick：哨兵元素，保证在stack单调递增时，最后仍然能够计算
    heights.push_back(0);

    // 初始化stack
    int res = 0;
    stack<int> S;
    for (size_t i = 0; i < heights.size(); ++i) {
        // 这里计算的面积是区间(S.top().top(), i) 开区间包裹的矩形面积
        while (!S.empty() && heights[S.top()] > heights[i]) {
            int idx = S.top(); S.pop();
            int h = heights[idx];

            int prevIndex = S.empty() ? -1 : S.top();
            int w = i - prevIndex - 1;
            res = max(res, w * h);
        }
        S.push(i);
    }

    // reset 哨兵元素
    heights.pop_back();
    return res;
}


#if 0
int main() {
    vector<int> v = { 2, 1, 3, 1, 1, 1 };
    vector<int> v2 = { 2, 1, 5, 6, 2, 3 };
    vector<int> v3 = { 4, 2, 0, 3, 2, 5 };
    int ans = largestRectangleArea(v3);
    cout << ans << endl;
    return 0;
}
#endif // 0