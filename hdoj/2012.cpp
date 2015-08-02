#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int IsPrime(int n)
{
	if (n <= 1) return 0;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int x, y;
	int n;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0) break;

		int ok = 1;
		for (n = x; n <= y; ++n)
		{
			int y = n * n + n + 41;
			if (!IsPrime(y))
			{
				ok = 0;
				break;
			}
		}

		if (ok == 1) printf("OK\n");
		else printf("Sorry\n");
	}

	return 0;
}
#endif //0