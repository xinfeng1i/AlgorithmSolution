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
#include <stack>
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


/*
 * Method 3: 单调栈，这种方法相当于是逐层填水的方式
 *
 * 维护一个单调栈，判断当前高度与栈顶元素的大小，如果栈为空或者比栈顶元素小则入栈（栈内保持单调递减）；
 * 否则，则出栈元素，且当前元素与新的栈顶元素形成的区间，为填水的区间，填水量为区间（较低端高度-出栈元素高度）* 宽度
 * 不断出栈计算，知道栈顶元素大于当前元素，则继续入栈。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 *
 */
int trapRainWater3(vector<int> &heights) {
    if (heights.size() <= 2) return 0;
    int ans = 0;
    
    stack<int> indexStack;
    int i = 0;
    int n = (int) heights.size();
    while (i < n) {
        while (!indexStack.empty() && heights[indexStack.top()] <= heights[i]) {
            int toFillIndex = indexStack.top();
            indexStack.pop();
            // printf("i = %d, fillIndex = %d\n", i, toFillIndex);
            
            if (indexStack.empty()) break;
            int width = i - indexStack.top() - 1;
            int fillHeight = min(heights[indexStack.top()], heights[i]) - heights[toFillIndex];
            
            // printf("    width = %d, fillHeight = %d, water = %d\n", width, fillHeight, width * fillHeight);
            ans += fillHeight * width;
        }
        indexStack.push(i);
        i++;
    }
    return ans;
}

/*
 * Method 4: 左右挡板法
 *
 * 该方法其实与方法2类似，基本思想是：水位是由左右挡板中较低的挡板决定的。因此，在遍历过程中比较左右挡板的高度，
 * 如果左侧挡板较低，则左指针不断累积 water，直到遇到更高的左侧挡板；否则，右指针不断累积 water，直到遇到更高
 * 的右侧挡板.
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
int trapRainWater4(vector<int> &heights) {
    if (heights.size() <= 2) return 0;
    
    int ans = 0;
    
    int n = (int) heights.size();
    int i = 0;
    int j = n - 1;
    int max_left = 0;
    int max_right = 0;
    while (i < j) {
        if (max_left <= max_right) {
            if (heights[i] <= max_left) {
                ans += max_left - heights[i];
                i++;
            } else {
                max_left = max(max_left, heights[i]);
            }
        } else {
            if (heights[j] <= max_right) {
                ans += max_right - heights[j];
                j--;
            } else {
                max_right = max(max_right, heights[j]);
            }
        }
    }
    
    return ans;
}



#if 0
int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};      // expected answer: 6
    // vector<int> heights = {100,50,99,50,100,50,99,50,100,50};   // expected answer: 202
    
    int result = trapRainWater4(heights);  // expected answer: 6
    printf("answer water = %d\n", result);
    
    return 0;
}
#endif //0

