//
//  539_移动零.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/9/18.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;


/*
 * 通向双指针
 * Time: O(n)
 * Space: O(1)
 *
 * 击败 100% 答案
 */
void moveZeroes(vector<int> &nums) {
    if (nums.size() <= 1) return;
    
    int n = (int) nums.size();
    int idx = 0;  // 指向待放置元素
    
    // 循环不变式：(-inf, idx) 都是非零元素
    // 初始化：(-inf, -1) 是非零元素
    // 循环：如果 i 是非零，循环后仍然保持
    //      如果 i 是零，则 idx 不动，仍然保持
    // 结束：idx 左侧存放了数组中所有的非零元素
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            nums[idx] = nums[i];
            idx++;
        }
    }
    
    // 把 idx 之后的所有元素置为零
    while (idx < n) {
        nums[idx] = 0;
        idx++;
    }
    
    return;
}

void printV(const vector<int>& v) {
    for (int x: v) {
        printf(" %d", x);
    }
    printf("\n");
}

int main() {
    // expected: [1, 3, 12, 0, 0]
    // vector<int> v1 = {0, 1, 0, 3, 12};
    
    // expected: [3, 1, 0, 0, 0]
    vector<int> v1 = {0, 0, 0, 3, 1};
    
    printf("before:\n");
    printV(v1);
    
    moveZeroes(v1);
    
    printf("after:\n");
    printV(v1);
    
    return 0;
}
