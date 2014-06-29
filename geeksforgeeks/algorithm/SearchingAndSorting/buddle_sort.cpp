#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;


/*
 * Buddle Sort:
 * every time, compare the two adjacent element, if not sorted
 * swap them, after the first loop, the max element goto the last
 *
 * LOOP INVARIANT: the last k element is sorted
 *				   INIT: the last 0 elem sorted
 *				   Keep: every time the one element goto the last
 *				   LAST: k = n - 1; the last n - 1 element sorted
 *
 * Time Complexity: O(n^2)
 */
void buddleSort(int a[], int n)
{
	for (int k = 0; k < n - 1; ++k)
	{
		for (int i = 1; i < n - k; ++i)
		{
			if (a[i-1] > a[i])
			{
				swap(a[i-1], a[i]);
			}
		}
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int a[] = {9, 3, 6, 7, 1, 5, 2};
	int n = sizeof(a) / sizeof(a[0]);

	printf("Before Sort:\n");
	printArray(a, n);

	buddleSort(a, n);

	printf("After Sort:\n");
	printArray(a, n);


	return 0;
}
