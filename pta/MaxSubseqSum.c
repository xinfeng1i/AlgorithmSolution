#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* O(n^3) */
int MaxSubseqSum1(int a[], int n)
{
	int maxsum = 0;
	int i, j, k;
	for (i = 0; i < n; ++i) {
		for (j = i; j < n; ++j) {
			int cursum = 0;
			for (k = i; k <= j; ++k) {
				cursum += a[k];
			}
			if (cursum > maxsum) {
				maxsum = cursum;
			}
		}
	}
	return maxsum;
}

/* O(n^2) */
int MaxSubseqSum2(int a[], int n, int* start, int* end)
{
	int i, j;
	/* 全部都是负数的情况 */
	int allneg = 1;
	for (i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			allneg = 0;
			break;
		}
	}
	if (allneg) {
		*start = a[0];
		*end = a[n-1];
		return 0;
	}
	
	int maxsum = 0;
	int cursum = 0;
	*start = 0; // 初始化为0很有必要，能够有效解决仅包含负数和0的情况 
	*end = 0;
	for (i = 0; i < n; ++i) {
		cursum = 0;
		for (j = i; j < n; ++j) {
			cursum += a[j];
			if (cursum > maxsum) {
				maxsum = cursum;
				*start = a[i];
				*end = a[j];
			}
		}
	}
	return maxsum;
}

/*  Divide and conquer O(nlogn) */
int MaxSubseqSumRecur(int a[], int left, int right)
{
	if (left > right) return 0;
	if (left == right) return MAX(0, a[left]);

	int maxsum = 0;
	int leftsum = 0;
	int rightsum = 0;
	int mid = left + (right - left) / 2;
	leftsum = MaxSubseqSumRecur(a, left, mid);
	rightsum = MaxSubseqSumRecur(a, mid + 1, right);
	maxsum = MAX(leftsum, rightsum);

	int tmp1 = 0;
	int tmp2 = 0;
	int cursum = 0;
	int i;

	for (i = mid + 1; i <= right; ++i) {
		cursum += a[i];
		if (cursum > tmp1) {
			tmp1 = cursum;
		}
	}

	cursum = 0;
	for (i = mid; i >= left; --i) {
		cursum += a[i];
		if (cursum > tmp2) {
			tmp2 = cursum;
		}
	}

	maxsum = MAX(maxsum, (tmp1 + tmp2));
	return maxsum;
}

int MaxSubseqSum3(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	return MaxSubseqSumRecur(a, left, right);
}

/* O(n) 的在线算法 */
int MaxSubseqSum4(int a[], int n, int* start, int* end)
{
	int i;
	/* 判断全是负数的情况 */
	int allneg = 1;
	for (i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			allneg = 0;
			break;
		}
	}
	if (allneg) {
		*start = a[0];
		*end = a[n-1];
		return 0;
	}
	
	int maxsum = 0;
	int cursum = 0;
	*start = 0;
	*end = 0;
	int startpos = 0;
	for (i = 0; i < n; ++i) {
		cursum += a[i];
		if (cursum > maxsum) {
			maxsum = cursum;
			*end = a[i];			// 发现更大的子列和，更新起始和终止位置 
			*start = a[startpos];
		}
		if (cursum < 0) {
			cursum = 0;				// 前面的所有和负数，新的起点为下一个位置 
			startpos = i + 1;
		}
	}
	return maxsum;
}

#define MAXN 100000
int a[MAXN];
int i, n;

int main()
{
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}


	int start = 0, end = 0;
	int ans2 = MaxSubseqSum4(a, n, &start, &end);
	printf("%d %d %d\n", ans2, start, end);

	return 0;
}
