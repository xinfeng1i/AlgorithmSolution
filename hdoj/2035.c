#include <stdio.h>
#include <stdlib.h>

#define MOD 1000

int main()
{
	int A, B, i;
	int ans;
	while (1) {
		scanf("%d %d", &A, &B);
		if (A == 0 && B == 0) break;
		ans = 1;
		for (i = 0; i < B; ++i) {
			ans = (ans * A) % MOD;
		}
		ans %= MOD;
		printf("%d\n", ans);
	}
	return 0;
}
