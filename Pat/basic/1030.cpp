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

const int MAX_N = 100010;
typedef long long llong;
llong A[MAX_N];

int main()
{
	//freopen("in.txt", "r", stdin);
	int n = 0;
	llong p = 0;
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &A[i]);
	}

	sort(A, A + n);
	int cnt = 0;
	for (int j = n - 1; j >= 0; --j)
	{
		llong M = A[j];
		llong m = (llong)ceil(double(M) / p);
		auto it = lower_bound(A, A + j + 1, m); // binary search

		if (it == A + j + 1) continue; // cannot find
		int i = it - A;
		if (j - i + 1 > cnt)
		{
			cnt = j - i + 1;
		}
	}

	printf("%d\n", cnt);
	return 0;
}

// Using binary searching reduce complexity O(n^2) to O(nlogn)