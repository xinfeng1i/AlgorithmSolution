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
 * ʹ�����εݹ飬��������ʱ�临�Ӷ�Ϊ:O(n)
 * �ô���ᵼ�³�ʱ
 */
int findPeak_Method1(vector<int>& A) {
    int left = 0;
    int right = (int)A.size() - 1;
    return findPeakUtil(A, left, right);
}


/*
 * Method2˼·����������Ŀ�ͷ�����򣬽�β�ǽ�������һ������peak
 * ÿ�������м�㣬������������׶Σ������һ������peak;��֮��ǰ���һ������ peak
 * ʱ�临�Ӷȣ�O(n)
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
