#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	double n;
	int m;
	double ret = 1.0;

	while (scanf("%lf %d", &n, &m) != EOF)
	{
		ret = 0.0;
		for (int i = 1; i <= m; ++i)
		{
			ret += n;
			n = sqrt(n);
		}
		printf("%.2lf\n", ret);
	}
	return 0;
}
#endif //0