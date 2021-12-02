#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

int findPeakUtil(vector<int>& A, int begin, int end) {
    if (end - begin + 1 < 3) return -1;

    int mid = begin + (end - begin) / 2;
    if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
        return mid;
    }

    int idx1 = findPeakUtil(A, begin, mid);
    if (idx1 != -1) return idx1;

    int idx2 = findPeakUtil(A, mid, end);
    if (idx2 != -1) return idx2;

    return -1;
}

/*
 * 使用两次递归，最差情况下时间复杂度为:O(n)
 * 该代码会导致超时
 */
int findPeak_Method1(vector<int>& A) {
    int left = 0;
    int right = (int)A.size() - 1;
    return findPeakUtil(A, left, right);
}


/*
 * Method2思路：由于数组的开头是升序，结尾是降序，所以一定存在peak
 * 每次搜索中间点，如果处于上升阶段，则后半段一定存在peak;反之，前半段一定存在 peak
 * 时间复杂度：O(n)
 */
int findPeak_Method2(vector<int>& A) {
    int left = 0;
    int right = (int)A.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < A[mid + 1]) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    return A[left] > A[right] ? left : right;
}
