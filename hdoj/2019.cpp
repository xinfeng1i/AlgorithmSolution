#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
int A[110];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (m == 0 && n == 0) break;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &A[i]);
		}

		int i = 0;
		for (i = 0; i < n; ++i)
		{
			if (m <= A[i]) break;
		}

		for (int j = n - 1; j >= i; --j)
			A[j + 1] = A[j];
		A[i] = m;

		for (int j = 0; j <= n; ++j)
		{
			if (j != 0) printf(" %d", A[j]);
			else printf("%d", A[j]);
		}
		printf("\n");
	}
	return 0;
}
#endif //0