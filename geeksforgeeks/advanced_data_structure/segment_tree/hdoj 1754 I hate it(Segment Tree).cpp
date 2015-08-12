#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 200010;
int A[MAX_N];
int st[5 * MAX_N];

int getmid(int left, int right)
{
	return left + (right - left) / 2;
}

int buildtree(int* A, int left, int right, int* st, int idx)
{
	if (left == right) return st[idx] = A[left];
	int mid = getmid(left, right);
	st[idx] = max(buildtree(A, left, mid, st, idx * 2 + 1),
		buildtree(A, mid + 1, right, st, idx * 2 + 2));
	return st[idx];
}

void updateutil(int i, int diff, int* st, int idx, int s, int e)
{
	if (i < s || i > e) return;

	if (s == e)
	{ // NOTE: this is not the same with sum, only leaf node need to +=
		st[idx] += diff;
		return;
	}
	else
	{ 
		int mid = getmid(s, e);
		updateutil(i, diff, st, 2 * idx + 1, s, mid);
		updateutil(i, diff, st, 2 * idx + 2, mid + 1, e);
		st[idx] = max(st[idx * 2 + 1], st[2 * idx + 2]);
	}
}

void update(int* A, int n, int i, int diff)
{
	A[i] += diff;
	updateutil(i, diff, st, 0, 0, n - 1);
}

int getmaxutil(int qs, int qe, int* st, int idx, int s, int e)
{
	if (qs <= s && qe >= e) return st[idx];
	if (qe <  s || qs >  e) return INT_MIN;
	int mid = getmid(s, e);
	return max(getmaxutil(qs, qe, st, 2 * idx + 1, s, mid),
		getmaxutil(qs, qe, st, 2 * idx + 2, mid + 1, e));
}

int getmax(int* A, int n, int qs, int qe)
{
	return getmaxutil(qs, qe, st, 0, 0, n - 1);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n = 0; int m = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(A, 0, sizeof(A));
		for (int i = 0; i < 5 * MAX_N; ++i) st[i] = INT_MIN;

		for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
		buildtree(A, 0, n - 1, st, 0);

		char buf[10]; int a = 0; int b = 0;
		for (int i = 0; i < m; ++i)
		{
			scanf("%s %d %d", buf, &a, &b);
			if (buf[0] == 'Q')
			{
				if (a > b) swap(a, b);
				int ans = getmax(A, n, a - 1, b - 1);
				printf("%d\n", ans);
			}
			else if (buf[0] == 'U')
			{
				int diff = b - A[a - 1];
				update(A, n, a - 1, diff);
			}
		}
	}
	return 0;
}