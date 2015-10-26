#include <stdio.h>
#include <stdlib.h>

#define N 60
long long Fib[N] = { 0 };

/* Recursion: f[n+1] = f[n] + f[n-2] */
void Preprocess()
{
	int i;
	Fib[1] = 1;
	Fib[2] = 2;
	Fib[3] = 3;
	for (i = 4; i < N; ++i) Fib[i] = Fib[i-1] + Fib[i-3];
}

int main()
{
	int n;
	Preprocess();
	for (;;) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", Fib[n]);
	}
	return 0;
}
