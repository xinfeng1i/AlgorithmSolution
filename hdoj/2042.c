#include <stdio.h>
#include <stdlib.h>

long long NumofSheep(int a);

int main()
{
	int n, a;
	register int i;
	long long num;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a);
		num = NumofSheep(a);
		printf("%lld\n", num);
	}
	return 0;
}

long long NumofSheep(int a)
{
	long long n = 3;
	while (a--) {
		n = (n - 1) * 2;
	}
	return n;
}
