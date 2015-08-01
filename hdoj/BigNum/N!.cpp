#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if 0
#define N 50050

int ret[N];
int tmp[N];
char strn[N];
int intn[N];
int pos = 0;

void product(int* A, int nA, int* B, int nB, int *C);


void nfrac(int n)
{
	for (int i = 0; i < N; ++i) ret[i] = 0;
	ret[0] = 1;

	for (int i = n; i >= 1; --i)
	{
		// covert n to str
		sprintf(strn, "%d", i);
		int nlen = strlen(strn);

		// ready B
		for (int j = 0; j < N; ++j) intn[j] = 0;
		pos = 0;
		for (int j = nlen - 1; j >= 0; --j) intn[pos++] = strn[j] - '0';

		// ready C
		for (int j = 0; j < N; ++j) tmp[j] = 0;

		// C = A * B
		pos = N - 1;
		while (pos >= 0 && ret[pos] == 0) pos--;
		product(ret, pos + 1, intn, nlen, tmp);

		// update ret to C
		for (int k = 0; k < N; ++k) ret[k] = tmp[k];		
	}
}

// C = A * B
void product(int* A, int nA, int* B, int nB, int *C)
{
	// init
	for (int i = 0; i < N; ++i) C[i] = 0;
	for (int i = 0; i < nB; ++i)
	{
		int x = B[i];
		int xpos = i;

		// product
		int pos = xpos;
		for (int j = 0; j < nA; ++j)
		{
			C[pos++] += x * A[j];
		}

		// carry
		for (int j = 0; j < N - 1; ++j)
		{
			if (C[j] >= 10)
			{
				C[j + 1] += C[j] / 10;
				C[j] %= 10;
			}
		}

	}
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			printf("1\n");
			continue;
		}

		clock_t start = clock();
		nfrac(n);
		char strC[N];
		memset(strC, '\0', N);
		pos = N - 1;
		while (pos >= 0 && ret[pos] == 0) pos--;

		int i = 0;
		while (pos >= 0)
		{
			strC[i++] = ret[pos--] + '0';
		}
		strC[i] = '\0';
		

		printf("%s\n", strC);
		clock_t end = clock();
		//printf("cost time: %f\n", double(end - start) / CLOCKS_PER_SEC);
	}

	return 0;
}
#endif //0

// 总结：
// 1. 计算两个大整数的乘积， 复杂度 N * nB
// 2. 对于 1...n 的每个数计算一次，总复杂度为 n * N * nB = n^2 * N
// 3. TLE