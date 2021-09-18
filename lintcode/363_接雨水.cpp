//
//  363_接雨水.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/9/16.
//

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * Method1
 *
 * 分别计算左边的最大高度和右边的最大高度，然后逐列计算water数量
 * Time: O(n)
 * Space: O(n)
 */
int trapRainWater(vector<int> &heights) {
    int answer = 0;
    
    if (heights.size() <= 2) {
        return 0;
    }
    
    int n = (int) heights.size();
    vector<int> maxLeft;
    vector<int> maxRight;
    for (int i = 0; i < n; ++i) {
        maxLeft.push_back(0);
        maxRight.push_back(0);
    }
    
    for (int i = 1; i < n; ++i) {
        maxLeft[i] = max(maxLeft[i-1], heights[i-1]);
    }
    
    for (int j = n - 2; j >= 0; --j) {
        maxRight[j] = max(maxRight[j+1], heights[j+1]);
    }
    
    for (int i = 1; i <= n-2; ++i) {
        int h = min(maxLeft[i], maxRight[i]);
        if (h >= heights[i]) {
            answer += h - heights[i];
        }
    }
    
    return answer;
}


/*
 * Method 2
 *
 * 如果能装水，必然从左右两侧较低的开始
 * 所以每次比较拿到左右两侧较低的挡板，并且一直开始往中间装水，直到遇到更高的挡板，则更新挡板高度重新迭代
 *
 * 双指针
 * Time：O(n)
 * Space: O(1)
 */
int trapRainWater2(vector<int> &heights) {
    int n = (int) heights.size();
    if (n <= 2) {
        return 0;
    }
    
    // 表示当前左右两侧挡板较低的一侧的挡板的高度
    int min_height = 0;
    int l = 0;
    int r = n - 1;
    int ans = 0;
    
    while (l < r) {
        while (l < r && heights[l] <= min_height) {
            ans += min_height - heights[l];
            l++;
        }
        while (l < r && heights[r] <= min_height) {
            ans += min_height - heights[r];
            r--;
        }
        min_height = min(heights[l], heights[r]);
    }
    
    return ans;
}

#if 1
int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};      // expected answer: 6
    // vector<int> heights = {100,50,99,50,100,50,99,50,100,50};   // expected answer: 202
    
    int result = trapRainWater2(heights);  // expected answer: 6
    printf("water = %d\n", result);
    
    return 0;
}
#endif //0

