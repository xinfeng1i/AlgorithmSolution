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


// 单调栈问题
// 对于任意位置x1<x2，如果h1<h2，那么对于某个y如果满足h2，其必然满足h1
// 暗示可以使用一个单调递减栈
// Time: O(n)
// Space: O(n)
vector<int> dailyTemperatures(vector<int>& t) {
    int n = (int)t.size();
    vector<int> ans(n, 0);

    stack<int> S;
    for (int i = 0; i < n; ++i) {
        while (!S.empty() && t[S.top()] < t[i]) {
            int idx = S.top(); S.pop();
            // cout << "Pop: <" << idx << " " << t[idx] << ">" << endl;
            ans[idx] = i - idx;
        }
        S.push(i);
        // cout << "Push: <" << i << " " << t[i] << ">" << endl;
    }
    return ans;
}


int main() {
    vector<int> v = { 73,74,75,71,69,72,76,73 };
    vector<int> v2 = { 30,40,50,60 };
    vector<int> v3 = {30, 60, 90};
    vector<int> ans = dailyTemperatures(v);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;

}