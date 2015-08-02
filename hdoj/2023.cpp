#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
int A[55][10];
double s[55];
double grade[10];

int main()
{
	int n, m;
	int score;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; ++i)
		{
			s[i] = 0.0;
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &score);
				A[i][j] = score;
				s[i] += score;
			}
			s[i] = s[i] / (double)m;
		}

		for (int j = 1; j <= m; ++j)
		{
			grade[j] = 0.0;
			for (int i = 1; i <= n; ++i)
			{
				grade[j] += A[i][j];
			}
			grade[j] /= (double)n;
		}

		int cnt = 0;
		int ok;
		for (int i = 1; i <= n; ++i)
		{
			ok = 1;
			for (int j = 1; j <= m; ++j)
			{
				if ((double)A[i][j] < grade[j])
				{
					ok = 0;
				}
			}

			if (ok) cnt++;
		}

		for (int i = 1; i <= n; ++i)
		{
			if (i == 1) printf("%.2lf", s[i]);
			else printf(" %.2lf", s[i]);
		}
		printf("\n");

		for (int j = 1; j <= m; ++j)
		{
			if (j == 1) printf("%.2lf", grade[j]);
			else printf(" %.2lf", grade[j]);
		}
		printf("\n");

		printf("%d\n", cnt);
		printf("\n");

	}
	return 0;
}
#endif //0