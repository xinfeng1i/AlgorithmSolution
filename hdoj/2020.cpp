#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
int cmp(const void* a, const void* b)
{
	return abs(*(const int*)b) - abs(*(const int*)a);
}

int A[110];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &A[i]);
		}

		qsort(A, n, sizeof(A[0]), cmp);

		for (int i = 0; i < n; ++i)
		{
			if (i == 0) printf("%d", A[i]);
			else printf(" %d", A[i]);
		}
		printf("\n");
	}
	return 0;
}
#endif //0