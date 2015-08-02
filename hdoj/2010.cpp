#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int IsFlower(int n)
{
	int a = n / 100;
	int b = (n % 100) / 10;
	int c = n % 10;
	if (n == a * a * a + b * b * b + c * c * c)
		return 1;
	else
		return 0;
}

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int has = 0;
		for (int i = m; i <= n; ++i)
		{
			if (IsFlower(i))
			{
				if (has == 0) 
				{
					has = 1;
					printf("%d", i);
				}
				else
				{
					printf(" %d", i);
				}
			}
		}

		if (has == 0) printf("no\n");
		else printf("\n");
	}
	return 0;
}
#endif //0