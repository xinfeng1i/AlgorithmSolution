#include <stdio.h>
#include <stdlib.h>

#define N 50010
int f[N] = { 0 };

int main()
{
	int n;
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 1)
		{
			printf("1\n");
			continue;
		}

		// init f[]
		for (i = 1; i < N; ++i) f[i] = 0;
		f[0] = 1;

		// n!
		for (i = 1; i <= n; ++i)
		{
			int x = i;
			int carry = 0;
			for (j = 0; j < N; ++j)
			{
				int s = f[j] * x + carry;
				f[j] = s % 10;
				carry = s / 10;
			}
		}

		// skip leading zeros
		for (i = N - 1; i >= 0; --i)
		{	
			if (f[i] != 0) break;
		}


		for (j = i; j >= 0; --j)
		{
			printf("%d", f[j]);
		}
		printf("\n");

	}

	return 0;
}

// 总结：
// 1. 对于大整数的每个数位和 B 数字直接相乘减少乘法次数，时间复杂度为 O(n * N)
// 2. AC