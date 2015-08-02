#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int n;
	int x;
	int ret = 1;
	while (scanf("%d", &n) != EOF)
	{
		ret = 1;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			if (x % 2 != 0) ret *= x;
		}
		printf("%d\n", ret);
	}
	return 0;
}
#endif //0