#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
int main()
{
	int n;
	int x;
	int cnt;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;

		cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			cnt += x / 100;
			x %= 100;
			cnt += x / 50;
			x %= 50;
			cnt += x / 10;
			x %= 10;
			cnt += x / 5;
			x %= 5;
			cnt += x / 2;
			x %= 2;
			cnt += x;
		}

		printf("%d\n", cnt);
	}
}
#endif //0