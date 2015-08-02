#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int m, n;
	long  x = 0;
	long  y = 0;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		x = 0;
		y = 0;
		if (m > n)
		{
			int tmp = m;
			m = n;
			n = tmp;
		}
		for (int i = m; i <= n; ++i)
		{
			if (i % 2 == 0) x += i * i;
			else y += i * i * i;
		}

		printf("%ld %ld\n", x, y);
	}
	return 0;
}
#endif //0

// 总结：有可能大数在前