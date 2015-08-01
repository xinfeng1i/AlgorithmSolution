#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int t;
	while (scanf("%d", &t) != EOF)
	{
		if (t < 0 || t > 100)
		{
			printf("Score is error!\n");
		}
		else if (t >= 90)
		{
			printf("A\n");
		}
		else if (t >= 80)
		{
			printf("B\n");
		}
		else if (t >= 70)
		{
			printf("C\n");
		}
		else if (t >= 60)
		{
			printf("D\n");
		}
		else
		{
			printf("E\n");
		}
	}
	return 0;
}
#endif //0