#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

/**
 * 3-way partatition
 * < pivot....==pivot...>pivot
 */
void sortColors(int A[], int n)
{
	if (n <= 1) return;
	int lt = 0;		// less than pivot
	int gt = n - 1; // greater than pivot
	int i = 0;
	while (i <= gt)
	{
		// invariant: (-, lt) == 0, (gt, -) == 2
		if (A[i] == 0)
		{
			swap(A[i], A[lt]);
			i++;
			lt++;
		}
		else if (A[i] == 2)
		{
			swap(A[i], A[gt]);	
			gt--;
		}
		else
		{
			i++;
		}
	}
	return;
}

int main()
{
	int A[5] = {0, 1, 2, 0, 1};
	for (int i = 0; i < 5; ++i) printf(" %d", A[i]);
	printf("\n");
	sortColors(A, 5);
	for (int i = 0; i < 5; ++i) printf(" %d", A[i]);
	printf("\n");
	return 0;
}
