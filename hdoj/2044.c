#include <stdio.h>
#include <stdlib.h>

long long nPath(int a, int b);

int main()
{
	int i, n, a, b;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		ans = nPath(a, b);
		printf("%lld\n", ans);
	}
	return 0;
}

/* Recursion: f[n] = f[n-1] + f[n-2], using long long to avoid Int Overflow */
long long nPath(int a, int b)
{
	if (a == b || a + 1 == b) return 1;
	long long num1 = 1;
	long long num2 = 1;
	long long tmp = 0;
	int cur = a + 1;
	while (cur < b) {
		tmp = num1 + num2;
		num1 = num2;
		num2 = tmp;
		cur++;
	}
	return tmp;
}
