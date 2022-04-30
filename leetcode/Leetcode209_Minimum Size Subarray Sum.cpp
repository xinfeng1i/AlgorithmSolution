#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = (int)nums.size();
    int ans = INT_MAX;

    int i = 0;
    int j = 0;
    int sum = 0;
    while (j < n) {
        // add this number to windows
        sum += nums[j];

        // check if satisfy the shrinking condition
        while (sum >= target) {
            int curLength = j - i + 1;
            ans = min(ans, curLength);

            sum -= nums[i];
            i++;
        }

        // expand the window to next position
        j++;
    }

    return ans == INT_MAX ? 0 : ans;
}


int main() {
    vector<int> v1 = { 1, 2, 3, 2, 2, 1 };
    cout << minSubArrayLen(5, v1) << endl;
    return 0;
}