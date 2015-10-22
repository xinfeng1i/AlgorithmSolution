#include <stdio.h>
#include <stdlib.h>

#define MAX_M  42
long long fib[MAX_M];

int main()
{
	int n, m;
	register int i;
	
	/* Preprocessing */
	fib[1] = 1;
	fib[2] = 1;
	for (i = 3; i < MAX_M; ++i) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &m);
		printf("%lld\n", fib[m]);
	}
	
	return 0;
}
