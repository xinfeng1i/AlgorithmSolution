#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * 二分查找变种题目：
 * 实际上就是根据中间元素与端点元素的比较来判断
 * 最小值位于那个区间：左边区间或者右边区间
 * 注意二分查找是，每次迭代必须保证区间总是缩小的，
 * 不然会出现死循环
 *
 * 1 2 3 4 5 6 7
 * case 1: 3 4 5 6 7 1 2
 * case 2: 6 7 1 2 3 4 5
 */
int minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;
    int n = static_cast<int>(rotateArray.size());
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int mid = i + (j-i)/2;
        if (rotateArray[mid] <= rotateArray[j]) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return rotateArray[i];
}

int main()
{
    //int a[7] = {1, 2, 3, 4, 5, 6, 7};
    //int a[7] = {3, 4, 5, 6, 7, 1, 2};
    int a[7] = {5, 6, 7, 1, 2, 3, 4};
    vector<int> v(a, a+7);
    cout << minNumberInRotateArray(v) << endl;
    return 0;
}
