//
//  521_去除重复元素.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/9/19.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * 方法1:
 * 1. 使用哈希表判断重复元素
 * 2. 使用双指针 re-assign
 *
 * Time: O(n)
 * Space: O(n)
 *
 */
int deduplication(vector<int> &nums) {
   int n = (int) nums.size();

   set<int> s;
   int idx = 0;
   for (int i = 0; i < n; ++i) {
       if (s.find(nums[i]) == s.end()) {
           nums[idx] = nums[i];
           idx++;
           s.insert(nums[i]);
       }
   }

   return idx;
}


/*
 * 方法2:
 * 1. 先排序 O(nlogn)
 * 2. 变成了已序数组的去重问题 O(n) 时间内解决
 *
 * Time: O(nlogn)
 * Space: O(1)
 */
int deduplication2(vector<int> &nums) {
    int n = (int) nums.size();
    if (n <= 1) return n;
    
    sort(nums.begin(), nums.end());
    int idx = 0;
    int i = 0;
    while (i < n) {
        // 找到一下个和i不想等的元素的位置j
        int j = i + 1;
        while (j < n && nums[j] == nums[i]) j++;
        
        nums[idx] = nums[i];
        idx++;
        
        i = j;
    }
    
    return idx;
}


#if 0
int main() {
    // expected: {1, 3, 4, 2, ?, ?} 最后两个数字是什么不关心
    vector<int> v = {1,3,1,4,4,2};
    
    printf("Before:\n");
    for (int x: v) {
        printf("%d ", x);
    }
    printf("\n");
    
    int newSize = deduplication2(v);
    printf("After: \n");
    for (int i = 0; i < newSize; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}
#endif // 0
