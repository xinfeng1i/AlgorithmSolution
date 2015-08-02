#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int n;
	int score, max, min;
	double sum;

	while (scanf("%d", &n) != EOF)
	{
		max = -1;
		min = 10000;
		sum = 0.0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &score);
			if (score > max) max = score;
			if (score < min) min = score;
			sum += score;
		}
		sum = (sum - max - min) / double(n - 2);
		printf("%.2lf\n", sum);
	}
	return 0;
}
#endif //0