#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 110;
int A[MAX_N];
int B[MAX_N];

bool IsSortedLen(int* A, int n, int len)
{
	for (int s = 0; s < n; s += len)
	{
		int e = s + len;
		e = min(e, n);
		for (int j = s + 1; j < e; ++j)
		{
			if (A[j] >= A[j - 1]) continue;
			else return false;
		}
	}
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &B[i]);

	int flag = 0;
	int pos = n - 1;
	for (pos = n - 1; pos >= 0; pos--)
	{
		if (B[pos] == A[pos]) continue;
		else break;
	}

	if (pos < 0)
	{
		// B 和 A 完全相等，不能直接判定为 merge sort，因为
		// 插入排序如果前面部分有序，也可能出现 B 和 A 相等的情况
		// 此时需要进一步判定长度为2的子序列是否被merge
		flag = 2;
		if (!IsSortedLen(B, n, 2)) flag = 1;
	}
	else
	{ 
		int i = pos;
		for (i = pos; i >= 1; --i)
		{
			if (B[i] >= B[i - 1]) continue;
			else break;
		}

		if (i <= 0) flag = 1;
		else flag = 2;
	}


	if (flag == 1)
	{
		printf("Insertion Sort\n");
		for (pos = 0; pos + 1 < n; ++pos)
		{
			if (B[pos] <= B[pos + 1]) continue;
			else break;
		}

		if (pos + 1 < n)
		{
			int tmp = B[pos + 1];
			int j = pos;
			for (j = pos; j >= 0; j--)
			{
				if (B[j] >= tmp) B[j + 1] = B[j];
				else break;
			}
			B[j + 1] = tmp;
		}

		for (int i = 0; i < n; ++i)
		{
			if (i == 0) printf("%d", B[i]);
			else printf(" %d", B[i]);
		}
		printf("\n");
	}
	else if (flag == 2)
	{
		printf("Merge Sort\n");
		int maxlen = 1;
		while (maxlen < n) maxlen *= 2;

		int len = 2;
		for (len = 2; len <= maxlen; len *= 2)
		{
			if (IsSortedLen(B, n, len)) continue;
			else break;
		}

		if (len <= maxlen)
		{
			for (int s = 0; s < n; s += len)
			{
				int e = s + len;
				e = min(e, n);
				sort(B + s, B + e);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (i == 0) printf("%d", B[i]);
			else printf(" %d", B[i]);
		}
		printf("\n");
	}
	return 0;
}
