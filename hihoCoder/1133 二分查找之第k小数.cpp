#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

// 利用quicksort的partition在O(n)时间内找到第k小的数字
int Partition(vector<int>& A, int left, int right)
{
	assert(left <= right);
	int x = A[left];
	int i = left;
	int j = right + 1;
	while (true) {
		do {j--;} while (A[j] > x);
		do {i++;} while (i < j && A[i] <= x);
		if (i < j) swap(A[i], A[j]);
		else break;
	}
	swap(A[left], A[j]);
	return j;
}

int FindKthNumber(vector<int>& A, int left, int right, int k) {
	if (left > right) return -1; // empty interval
	if (k < 1 || k > (right-left+1)) return -1; // invalid k
	
	assert(left <= right);
	int mid = Partition(A, left, right);
	int rank = mid - left + 1;
	if (rank == k) {
		return A[mid];
	} else if (rank > k) {
		return FindKthNumber(A, left, mid-1, k);
	} else {
		return FindKthNumber(A, mid+1, right, k-rank);
	}
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> A(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	
	int ans = FindKthNumber(A, 0, n-1, k);
	printf("%d\n", ans);
	return 0;
}

