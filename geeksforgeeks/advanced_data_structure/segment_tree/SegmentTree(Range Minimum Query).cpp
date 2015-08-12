#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int GetMid(int left, int right)
{
	return left + (right - left) / 2;
}

/* build A[left, right] into segment tree, node store minimum */
int BuildTreeUtil(int* A, int left, int right, int* st, int idx)
{
	// only has one element
	if (left == right) return (st[idx] = A[left]);

	int mid = GetMid(left, right);
	int leftmin = BuildTreeUtil(A, left, mid, st, 2 * idx + 1);
	int rightmin = BuildTreeUtil(A, mid + 1, right, st, 2 * idx + 2);
	return st[idx] = min(leftmin, rightmin);
}

int* BuildTree(int* A, int n)
{
    // there has 2n-1 node, but the idx not continues from [0, 2n-1]
    // the size will be 2 * pow(2, ceil(log2(n))) - 1
    int h = (int)ceil(log2(n));
    int maxsize = 2 * (int)pow(2, h) - 1;
	int* st = new int[maxsize];   
	BuildTreeUtil(A, 0, n - 1, st, 0);
	return st;
}

int GetMinUtil(int* A, int left, int right, int* st, int idx, int s, int e)
{
	if (left <= s && right >= e) return st[idx];
	if (right < s || left > e) return INT_MAX;

	int mid = GetMid(s, e);
	int leftMin = GetMinUtil(A, left, right, st, 2 * idx + 1, s, mid);
	int rightMin = GetMinUtil(A, left, right, st, 2 * idx + 2, mid + 1, e);
	return min(leftMin, rightMin);
}

int GetMin(int* A, int n, int left, int right, int* st)
{
	if (left > right)
	{
		fprintf(stderr, "query range not legal!\n");
		return -1;
	}
	return GetMinUtil(A, left, right, st, 0, 0, n - 1);
}

int main()
{
	int A[] = {1, 3, 2, 7, 9, 11};
	int n = sizeof(A) / sizeof(A[0]);

	int* st = BuildTree(A, n);
	int qs = 5;
	int qe = 5;
	int minVal = GetMin(A, n, qs, qe, st);
	printf("Min A[%d, %d] = %d\n", qs, qe, minVal);

	return 0;
}

// 线段树经典应用：范围最小值查询