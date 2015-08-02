#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int n;
	double x;
	int a, b, c;
	while (1)
	{
		scanf("%d", &n);
		if (n == 0) break;

		a = 0;
		b = 0;
		c = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &x);
			if (x < -1E-8) a++;
			else if (x > 1E-8) c++;
			else b++;
		}
		printf("%d %d %d\n", a, b, c);
	}

	return 0;
}
#endif //0
