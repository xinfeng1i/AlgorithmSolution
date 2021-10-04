//
//  548_两数组的交集II.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/10/4.
//

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


/*
 * 排序+合并两个有序数组(模版)
 *
 * 时间复杂度：O(mlogm+nlogn)
 * 空间复杂度：O(1)
 */
vector<int> intersectionII(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    if (nums1.empty() || nums2.empty()) return ans;
    
    sort(nums1.begin(), nums1.end());   // mlogm
    sort(nums2.begin(), nums2.end());   // nlogn
    
    int n1 = (int) nums1.size();
    int n2 = (int) nums2.size();
    int i = 0;
    int j = 0;
    
    // m+n
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            int elem = nums1[i];
            ans.push_back(elem);
            
            i++;
            j++;
        }
    }
    
    return ans;
    
}

#if 0
int main() {
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    
    vector<int> ans = intersectionII(v1, v2);
    for (int x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}
#endif // 0
