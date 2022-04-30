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


int longestOnes(vector<int>& nums, int k) {
    int n = (int)nums.size();
    int quota = k;

    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < n) {
        // add to windows
        if (nums[j] == 0) quota--;

        // check if satisfy shrinking condition
        while (quota < 0) {
            if (nums[i] == 0) quota++;
            i++;
        }

        // expand to next position
        int curLength = j - i + 1;
        ans = max(ans, curLength);
        j++;
    }

    return ans;
}

#if 0
int main() {
    vector<int> v = { 1,1,1,0,0,0,1,1,1,1,0 };
    cout << longestOnes(v, 3) << endl;
    return 0;
}
#endif // 0