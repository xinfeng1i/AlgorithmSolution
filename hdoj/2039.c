#include <stdio.h>
#include <stdlib.h>

int CanFormTriangle(double a, double b, double c);

int main()
{
	int n, i;
	double a, b, c;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lf %lf %lf", &a, &b, &c);
		if (CanFormTriangle(a, b, c))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int CanFormTriangle(double a, double b, double c)
{
	if (a + b <= c) return 0;
	if (a + c <= b) return 0;
	if (b + c <= a) return 0;
	return 1;
}
