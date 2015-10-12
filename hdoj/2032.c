#include <stdio.h>
#include <stdlib.h>
#define MX_SIZE 1000

int A[MX_SIZE][MX_SIZE];
void PrintYangHui(int n);

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		PrintYangHui(n);
		printf("\n");
	}
	return 0;
}

void PrintYangHui(int n)
{
	if (n == 1) {
		printf("1\n");
		return;
	}
	
	int i, j;
	
	A[0][0] = 1;
	for (i = 1; i < n; ++i) {
		A[i][0] = 1;
		A[i][i] = 1;
		for (j = 1; j < i; ++j) {
			A[i][j] = A[i-1][j-1] + A[i-1][j];
		}
	}
	
	for (i = 0; i < n; ++i) {
		for (j = 0; j < i+1; ++j) {
			if (j != 0) printf(" %d", A[i][j]);
			else printf("%d", A[i][j]);
		}
		printf("\n");
	}
}
