#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	double x;
	while (scanf("%lf", &x) != EOF)
	{
		if (x < 1E-8) x = -x;
		printf("%.2lf\n", x);
	}
	return 0;
}
#endif //0