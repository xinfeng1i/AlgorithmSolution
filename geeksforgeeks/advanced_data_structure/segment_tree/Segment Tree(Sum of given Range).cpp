#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 
 * Segment Tree
 * In general, sum{A[l...r]} cost O(n) time and update A[i] = newval
 * cost O(1) time if we just uses array A[]
 * segment tree build a tree with O(2*n) space, recording the sum A[l, mid]
 * and A[mid+1,r] in the tree node, then the query operation of sum{A[l...r]} 
 * cost only O(logn) time, with price of update complexity A[i] = newval with
 * O(logn) time as well as O(2*n) extra space
 */

int get_mid(int left, int right)
{
	return left + (right - left) / 2;
}

// build tree recusively, build A[left, right] at node st[sidx]
int build_tree_util(int* A, int left, int right, int* st, int sidx)
{
	// base case: only one node, just assignment
	if (left == right) return (st[sidx] = A[left]);

	// recursively construct left and right subtree, store their sum
	// into current node
	int mid = get_mid(left, right);
	st[sidx] = build_tree_util(A, left, mid, st, 2 * sidx + 1) + 
		       build_tree_util(A, mid + 1, right, st, 2 * sidx + 2);
	return st[sidx];
}

int* build_tree(int *A, int n)
{
    // there has 2n-1 node, but the idx not continues from [0, 2n-1]
    // the size will be 2 * pow(2, ceil(log2(n))) - 1
    int h = (int)ceil(log2(n));
    int maxsize = 2 * (int)pow(2, h) - 1;
	int* st = new int[maxsize];    
	build_tree_util(A, 0, n - 1, st, 0);
	return st;
}

// return the sum of A[l, r]
int getsum_util(int* A, int ql, int qr, int* st, int sidx, int s, int e)
{
	// base case query interval [ql, qr] contains [s, e]
	if (ql <= s && qr >= e) return st[sidx];

	// query segment outside current node segment
	if (qr < s || ql > e) return 0;

	// overlap
	int mid = get_mid(s, e);
	return getsum_util(A, ql, qr, st, 2 * sidx + 1, s, mid) +
		getsum_util(A, ql, qr, st, 2 * sidx + 2, mid + 1, e);
}

int getsum(int* A, int n, int ql, int qr, int* st)
{
	if (ql > qr || ql < 0 || qr >= n)
	{
		fprintf(stderr, "query interval inlegal !\n");
		return -1;
	}

	return getsum_util(A, ql, qr, st, 0, 0, n - 1);
}

void update_value_util(int i, int diff, int* st, int sidx, int s, int e)
{
	// current interval [s, e] not contain this A[i], not need to update
	if (i < s || i > e) return;

	// update current node
	st[sidx] += diff;
	if (s <= e)
	{ // if this node is not leaf, update recur
		int mid = get_mid(s, e);
		update_value_util(i, diff, st, 2 * sidx + 1, s, mid);
		update_value_util(i, diff, st, 2 * sidx + 2, mid + 1, e);
	}
}

void update_value(int* A, int n, int i, int newval, int* st)
{
	if (i < 0 || i >= n)
	{
		fprintf(stderr, "array index not illegal\n");
		return;
	}
	int diff = newval - A[i];
	A[i] = newval;
	update_value_util(i, diff, st, 0, 0, n - 1);
}

int main()
{
	int A[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(A) / sizeof(A[0]);

	int* st = build_tree(A, n);
	printf("sum A[1..3] = %d\n", getsum(A, n, 1, 3, st));
	update_value(A, n, 5, 10, st);
	printf("sum A[1..3] = %d\n", getsum(A, n, 1, 3, st));

	return 0;
}

/*
 * Time complexity:
 * build tree - O(n)
 * query sum A[l...r] - O(logn)
 * update value A[i] = newval - O(logn)
 *
 * Space Complexity: O(n)
 * need (2 * n - 1) new node
 */
