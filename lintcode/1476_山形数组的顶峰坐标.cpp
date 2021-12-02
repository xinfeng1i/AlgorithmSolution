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

int peakIndexInMountainArray(vector<int>& A) {
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