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

vector<int> searchRange(vector<int> &A, int target) {
    vector<int> ans(2, -1);
    if (A.empty()) return ans;


    int n = (int)A.size();

    // find left bound
    int left = 0;
    int right = n - 1;
    int mid = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (A[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (A[left] != target) return ans;
    else ans[0] = left;


    // find right bound
    left = 0;
    right = n - 1;
    mid = -1;
    while (left < right) {
        mid = left + (right-left+1)/2;
        if (A[mid] <= target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    ans[1] = left;

    return ans;

}
