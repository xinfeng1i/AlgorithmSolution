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

int atMost(vector<int>& A, int k) {
    int i = 0; 
    int j = 0;
    int n = (int)A.size();

    int ans = 0;
    int oddCnt = 0;
    while (j < n) {
        if (A[j] % 2 == 1) {
            oddCnt++;
        }

        // 不满足条件，移动左指针
        while (oddCnt > k) {
            if (A[i] % 2 == 1) {
                oddCnt--;
            }
            i++;
        }
        // oddCnt <= k，区间 [i, j] 满足条件
        ans += j - i + 1;
        j++;
    }
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
}

#if 0
int main() {
    vector<int> v1 = { 1, 2, 3, 2, 2};
    cout << numberOfSubarrays(v1, 2) << endl;

    vector<int> v2 = { 1,1,2,1,1 };
    cout << numberOfSubarrays(v2, 3) << endl;

    vector<int> v3 = { 2, 4, 6 };
    cout << numberOfSubarrays(v3, 1) << endl;

    vector<int> v4 = { 2,2,2,1,2,2,1,2,2,2 };
    cout << numberOfSubarrays(v4, 2) << endl;
    return 0;
}
#endif // 0