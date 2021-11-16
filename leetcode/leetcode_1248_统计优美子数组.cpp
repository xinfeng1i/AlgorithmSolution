//
//  leetcode_1248_统计优美子数组.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/12.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * Method1: 滑动窗口问题
 * Time: O(n)
 * Space: O(1)
 */
int numberOfSubarrays(vector<int>& nums, int k) {
    if (nums.size() < k) return 0;
    
    int ans = 0;
    
    int n = (int) nums.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < n) {
        while (j < n && cnt < k) {
            if (nums[j] % 2 == 1) cnt++;
            j++;
        }
        if (j >= n && cnt < k) break;
        
        if (cnt == k) {
            int jj = j;
            int afterCnt = 0;
            while (jj < n && nums[jj] % 2 == 0) { afterCnt++; jj++; }
            
            while (cnt == k) {
                ans += afterCnt + 1;
                if (nums[i] % 2 == 1) cnt--;
                i++;
            }
            
        }
    }
    
    return ans;
}

int main() {
    // expected result: 16
    vector<int> v = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    
    // expected result: 0
    vector<int> v2 = {2, 4, 6};
    int k2 = 1;
    
    // expected result: 2
    vector<int> v3 = {1, 1, 2, 1, 1};
    int k3 = 3;
    
    int ans = numberOfSubarrays(v3, k3);
    printf("%d\n", ans);
    printf("Hello world\n");
    return 0;
}
