#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
double sum(int n)
{
	double ans = 0.0;
	double flag = 1.0;
	for (int i = 1; i <= n; ++i)
	{
		ans += flag * 1.0 / i;
		flag = -flag;
	}

	return ans;
}

int main()
{
	int m, n;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &n);
		double ans = sum(n);
		printf("%.2lf\n", ans);
	}
	return 0;
}
#endif //0