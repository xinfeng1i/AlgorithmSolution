#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/**
 * @param nums: The integer array.
 * @param target: Target number to find.
 * @return: The first position of target. Position starts from 0.
 */
int binarySearch(vector<int> &A, int target) {
    int left = 0;
    int right = (int)A.size() - 1;

    int mid = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (A[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (A[left] == target) return left;
    else return -1;
}
