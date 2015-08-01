#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
#define N 1010

int T = 0;
int A[N];
int B[N];
int C[N];
int i = 0;
int pos = 0;

char strA[N];
char strB[N];
char strC[N];


int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		// init
		memset(strA, '\0', N);
		memset(strB, '\0', N);
		memset(strC, '\0', N);
		for (i = 0; i < N; ++i) A[i] = 0;
		for (i = 0; i < N; ++i) B[i] = 0;
		for (i = 0; i < N; ++i) C[i] = 0;

		scanf("%s %s", strA, strB);

		int na = strlen(strA);
		int nb = strlen(strB);
		
		pos = 0;
		for (i = na - 1; i >= 0; --i)
		{
			A[pos++] = strA[i] - '0';
		}

		pos = 0;
		for (i = nb - 1; i >= 0; --i)
		{
			B[pos++] = strB[i] - '0';
		}

		// Add		
		for (i = 0; i < N; ++i)
		{
			C[i] = A[i] + B[i];
		}
		// Carry
		for (i = 0; i < N - 1; ++i)
		{
			if (C[i] >= 10)
			{
				C[i + 1] += C[i] / 10;
				C[i] %= 10;
			}
		}

		i = N - 1;
		while (i >= 0 && C[i] == 0) i--;

		pos = 0;
		while (i >= 0)
		{
			strC[pos++] = C[i] + '0';
			i--;
		}
		strC[pos] = '\0';

		if (nCase != 1) printf("\n");
		printf("Case %d:\n", nCase);
		printf("%s + %s = %s\n", strA, strB, strC);
		

	}
	return 0;
}
#endif //0

// 总结：大整数加法问题
// 1. 注意初始化数组为 0
// 2. 进位 10 边界情况
// 3. 输出格式控制

