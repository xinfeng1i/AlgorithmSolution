//
//  547_两数组的交集.cpp
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
 * Method1: 直接使用容器 Set（查找，插入，删除复杂度都是 logn)
 *
 * 时间复杂度: O(m*logn)
 * 空间复杂度: O(m+n)
 */
vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    
    set<int> s;
    for (int x: s1) {
        if (s2.find(x) != s2.end()) {
            s.insert(x);
        }
    }
    
    vector<int> ans(s.begin(), s.end());
    return ans;
}

/*
 * Method2: 不使用 Set 数据结构，直接使用同向双指针，先排序然后基本按照两个有序数据 Merge 的方式
 * 交替推进两个指针，如果碰到元素相同，则找到了一个交集元素.
 *
 * 时间复杂度：nlogn + mlogm + (m+n)
 * 空间复杂度：O(1)
 */
vector<int> intersection2(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    if (nums1.empty() || nums2.empty()) return ans;
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int n1 = (int) nums1.size();
    int n2 = (int) nums2.size();
    int i = 0;
    int j = 0;
    
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            int elem = nums1[i];
            ans.push_back(elem);
            
            while (i < n1 && nums1[i] == elem) i++;
            while (j < n2 && nums2[j] == elem) j++;
        }
    }
    
    return ans;
    
}

/*
 * Method3: 使用哈希表，将短数组存入哈希表，遍历长数组判断是否在哈希表内
 *
 * 时间复杂度：O(m)
 * 空间复杂度：O(n)，其中 m >= n
 */
vector<int> intersection3(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    if (nums1.empty() || nums2.empty()) return ans;
    
    vector<int> long_num;
    vector<int> short_num;
    if (nums1.size() >= nums2.size()) {
        long_num = nums1;
        short_num = nums2;
    } else {
        long_num = nums2;
        short_num = nums1;
    }
    
    unordered_set<int> result;
    unordered_set<int> s(short_num.begin(), short_num.end());
    for (int x: long_num) {
        if (s.find(x) != s.end()) {
            result.insert(x);
        }
    }
    
    return vector<int>(result.begin(), result.end());
}


#if 0
int main() {
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    vector<int> ans1 = intersection3(v1, v2);
    for (int x: ans1) {
        printf("%d ", x);
    }
    printf("\n");
    
    vector<int> v3 = {1, 2};
    vector<int> v4 = {2};
    vector<int> ans2 = intersection3(v3, v4);
    for (int x: ans2) {
        printf("%d ", x);
    }
    printf("\n");
    
    return 0;
}
#endif // 0
