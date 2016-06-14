#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一
// 按从大到小排序数组，然后切分成两个部分，前半部分为larger，后半
// 部分为smaller，然后将larger放在奇数位置，将smaller元素放在偶数位置
// 时间复杂度 O(nlogn), 空间复杂度 O(n)
void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int n = (int) nums.size();
    vector<int> larger(nums.begin(), nums.begin() + n/2);
    vector<int> smaller(nums.begin()+n/2, nums.end());

    int i = 0; int j = 0;
    for (int k = 0; k < n; ++k) {
        if (k % 2 == 0) {
            nums[k] = smaller[i++];
        } else {
            nums[k] = larger[j++];
        }
    }

    return;
}

// 方法二:
// 方法一中时间复杂度过高，主要来自于排序的O(nlogn)，而实际上我们并不需要
// 数组完全有序，只需要在奇数位置上放比中位数大的数和中位数，在偶数位置上放
// 中位数和比中位数小的数即可，因此可以在O(n)的时间内做到一次partition
// 方法一中空间复杂度的O(n)主要来自于需要对排序的数组做一次位置再分配，而下面的
// Index Mapping技术可以在partition过程中完成位置再分配，从而减小复杂度为O(1)
void wiggleSort(vector<int>& nums) {
    int n = (int) nums.size();
    nth_element(nums.begin(), nums.begin()+n/2, nums.end());
    int medium = nums[n/2];
    
    // Virtual Index Mapping
    #define nums(i) nums[(2*i+1) % (n|1)]
    
    // three way partitions,[>medium][==medium][<medium]
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
        if (nums(j) > medium) {
            swap(nums(i), nums(j));
            i++;
            j++;
        } else if (nums(j) < medium) {
            swap(nums(j), nums(k));
            k--;
        } else {
            j++;
        }
    }
}
