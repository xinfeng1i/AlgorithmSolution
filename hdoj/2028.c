#include <stdio.h>
#include <stdlib.h>

int GCDNums(int* A, int n);
int GCD(int a, int b);
int LCM(int a, int b);
int LCMNums(int* A, int n);

int main()
{
	int n; int i;
	int* A;
	int gcd;
	while (scanf("%d", &n) != EOF) {
		A = malloc(sizeof(int) * n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}
		gcd = LCMNums(A, n);
		printf("%d\n", gcd);
		free(A);
		A = NULL;
	}
	return 0;
}

int GCD(int a, int b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int LCM(int a, int b)
{
	/* 先除法后乘法保证不会发生整型溢出 */
	return a / GCD(a, b) * b;
}

int GCDNums(int* A, int n)
{
	if (n == 1) return *A;
	return GCD(A[n-1], GCDNums(A, n - 1));
}

int LCMNums(int* A, int n)
{
	if (n == 1) return *A;
	return LCM(A[n-1], LCMNums(A, n - 1));
}
