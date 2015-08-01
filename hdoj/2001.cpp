#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	double x1, y1;
	double x2, y2;
	double d;

	while (scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) == 4)
	{
		d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

		d = sqrt(d);
		printf("%.2lf\n", d);
		
	}
	return 0;
}
#endif //0

// 总结：
// double 输入用 %lf 而不是 %f