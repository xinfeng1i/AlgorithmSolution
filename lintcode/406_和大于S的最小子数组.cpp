//
//  406_和大于S的最小子数组.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/9.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;


/*
 * Method1: 滑动窗口经典问题
 * 不断移动右指针，找到满足条件的最大和；然后不断移动左指针，缩小窗口范围
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
int minimumSize(vector<int> &nums, int s) {
    if (nums.empty()) return -1;
    if (nums.size() == 1) {
        if (nums[0] == s) return 1;
        else return -1;
    }
    
    int ans = -1;
    
    int n = (int) nums.size();
    int i = 0;
    int j = 0;
    int curSum = 0;
    while (i < n) {
        while (j < n && curSum < s) {
            curSum += nums[j];
            j++;
        }
        if (j >= n && curSum < s) break;
        
        while (curSum >= s) {
            if (ans == -1) ans = j - i;
            else ans = min(ans, j - i);
            curSum -= nums[i]; i++;
        }
    }
    
    return ans;
}


#if 0
int main() {
    vector<int> v = {2,3,1,2,4,3};  // expected: 2
    int s = 7;
    
    //vector<int> v = {1, 2, 3, 4, 5};  // expected: -1
    //int s = 100;
    
    //vector<int> v = {100,50,99,50,100,50,99,50,100,50};  // expected: 4
    //int s = 250;
    
    int ans = minimumSize(v, s);
    printf("ans = %d\n", ans);
    return 0;
}
#endif // 0
