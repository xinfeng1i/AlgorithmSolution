#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	int n, m;
	int sum; int x;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		sum = 0;
		x = 2;
		int cnt = 0;
		int hasFirst = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += x;
			x += 2;
			cnt++;
			if (cnt == m || i == n - 1)
			{
				if (hasFirst == 0) 
				{
					printf("%d", sum / cnt); 
					hasFirst = 1;
				}
				else
				{
					printf(" %d", sum / cnt);
				}
				sum = 0;
				cnt = 0;
			}
		}
		printf("\n");
	}
	return 0;
}
#endif //0