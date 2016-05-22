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

int searchInsert(vector<int> &A, int target) {
    if (A.empty()) return 0;


    int left = 0;
    int right = (int)A.size() - 1;

    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (A[left] == target) return left;
    else if (A[left] > target) return left;
    else return left + 1;
}
