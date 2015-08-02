#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
#define N 110
int A[N];

void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	int n;
	int min = INT_MAX;
	int minIndex = -1;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		min = INT_MAX;
		minIndex = -1;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &A[i]);
			if (A[i] < min)
			{
				min = A[i];
				minIndex = i;
			}
		}

		swap(&A[0], &A[minIndex]);

		int hasFirst = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!hasFirst)
			{
				printf("%d", A[i]);
				hasFirst = 1;
			}
			else
			{
				printf(" %d", A[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
#endif //0