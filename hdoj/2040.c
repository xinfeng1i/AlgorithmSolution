#include <stdio.h>
#include <stdlib.h>

int QinHeNumber(int a, int b);

int main()
{
	int i, n;
	int a, b;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		if (QinHeNumber(a, b))
			printf("YES\n");
		else
			printf("NO\n");
	}
}


int QinHeNumber(int a, int b)
{
	int sum1 = 1;
	int sum2 = 1;
	int i;
	if (a == 0 || b == 0) return 0;
	for (i = 2; i < a; ++i) {
		if (a % i == 0) sum1 += i;
	}
	if (sum1 != b) return 0;

	for (i = 2; i < b; ++i) {
		if (b % i == 0) sum2 += i;
	}
	if (sum2 != a) return 0;
	
	return 1;
}
