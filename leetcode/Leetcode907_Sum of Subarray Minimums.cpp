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

//
// 单调stack问题，独立解决，但是中间调试了很长时间，需要进行复盘
// Time: O(N)
// Space: O(N)
//
int sumSubarrayMins(vector<int>& arr) {
    if (arr.empty()) return 0;

    int MOD = 1000000007;
    int ans = 0;

    arr.push_back(0);
    int n = (int)arr.size();

    stack<int> S;
    for (int i = 0; i < n; ++i) {
        while (!S.empty() && arr[S.top()] > arr[i]) {
            int idx = S.top(); S.pop();
            int prevIdx = S.empty() ? -1 : S.top();

            int num1 = idx - prevIdx - 1;  
            int num2 = i - idx - 1;

            if (num1 == 0) {
                ans = (ans % MOD + ((num2 + 1) * arr[idx]) % MOD) % MOD;
            }
            else if (num2 == 0) {
                ans = ((ans % MOD) + ((num1 + 1) * arr[idx]) % MOD) % MOD;
            }
            else {
                // 解决乘法溢出问题
                long long temp = (long long)(num1 + 1) * (long long)(num2 + 1) * arr[idx];
                long long temp2 = temp % MOD;
                ans = (ans + (long long)temp2) % MOD;
            }
        }
        S.push(i);
    }

    return ans % MOD;
}


#if 0
int main() {
    vector<int> v = { 3, 1, 2, 4 };  // 17
    vector<int> v2 = { 11,81,94,43,3 };  // 444
    vector<int> v3 = {51, 94, 11, 56}; // 318

    int ans = sumSubarrayMins(v3);
    cout << ans << endl;
    return 0;
}
#endif // 0