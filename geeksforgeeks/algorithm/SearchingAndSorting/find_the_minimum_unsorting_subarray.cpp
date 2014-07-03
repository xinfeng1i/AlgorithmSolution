#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int FindMinimumUnsortedSubArray(int a[], int n)
{
	// scanf from left to right, find the first elem that not sorted
	int s = 0;
	for (s = 0; s + 1 < n; ++s)
	{
		if (a[s] > a[s+1]) break;
	}

	if (s + 1 == n)
	{
		printf("The original is already sorted\n");
		return -1;
	}

	// scanf from right to left, find the first elem that not sorted
	int e = n - 1;
	for (e = n - 1; e - 1> 0; --e)
	{
		if (a[e] < a[e-1]) break;
	}
	if (e - 1 == 0)
	{
		printf("The original is already sorted\n");
		return -1;
	}

	// find the min and max value int [s, e];
	int subMin = a[s]; int subMax = a[e];
	for (int i = s; i <= e; ++i)
	{
		if (a[i] < subMin) subMin = a[i];
		if (a[i] > subMax) subMax = a[i];
	}

	// scanf [0, s-1] to find if all elems are <= subMin, if not, included the elem
	for (int i = 0; i <= s - 1; ++i)
	{
		if (a[i] > subMin) 
		{
			s = i;
			break;
		}
	}

	// scanf [e+1, n) to find if all elems are >= subMax, if not, included
	for (int i = n - 1; i >= e + 1; --i)
	{
		if (a[i] < subMax)
		{
			e = i;
			break;
		}
	}

	// the result is [s, e];
	printf ("The minimum unsorted subarray, sort which will sort the whole array\n");
	printf ("stating from %d to %d\n", s, e);

	return 0;
}

int main()
{
	int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(a) / sizeof(a[0]);

	int b[] = {1, 3, 5, 3};
	int nb = 4;

	FindMinimumUnsortedSubArray(a, n);
	FindMinimumUnsortedSubArray(b, nb);

	return 0;
}
