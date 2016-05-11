#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <assert.h>
#include <stdio.h>
using namespace std;

int Partition(vector<int>& A, int left, int right) {
    assert(left <= right);
    int x = A[left];
    int i = left;
    int j = right + 1;
    while (1) {
        do {j--;} while(A[j] > x);
        do {i++;} while (i < j && A[i] <= x);
        if (i < j) swap(A[i], A[j]);
        else break;
    }
    swap(A[left], A[j]);
    return j;
}

int BinarySearch(vector<int>& A, int target) {
    int n = (int)A.size();
    int left = 0;
    int right = n-1;
    while (left <= right) {
        int mid = Partition(A, left, right);
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, target;
    scanf("%d%d", &n, &target);
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    int ans = BinarySearch(A, target);
    if (ans != -1) ans += 1;
    printf("%d\n", ans);
    return 0;
}
