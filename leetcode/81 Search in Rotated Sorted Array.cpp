#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

bool search(vector<int>& A, int target) {
	int n = (int)A.size();
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int mid = left + (right-left) / 2;
		if (A[mid] == target) {
			return true;
		}
		
		if (A[mid] > A[right]) {
			if (A[left] <= target && target < A[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else if (A[mid] < A[right]) {
			if (A[mid] < target && target <= A[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} else {
			right--;
		}
	}
	
	if (A[left] == target) return true;
	else return false;
}
