#include <stdio.h>
#include <stdlib.h>

int A[110];
int B[110];
int C[110];

int SetDiff(int* A, int n1, int* B, int n2);
int IntCmp(const void* a, const void* b);

int main()
{
	int n1, n2;
	int i, j;
	int n3;
	while (1) {
		scanf("%d %d", &n1, &n2);
		if (n1 == 0 && n2 == 0)
			break;
		for (i = 0; i < n1; ++i) {
			scanf("%d", &A[i]);
		}
		for (j = 0; j < n2; ++j) {
			scanf("%d", &B[j]);
		}
		n3 = SetDiff(A, n1, B, n2);
		if (n3 == 0) {
			printf("NULL\n");
		} else {
			for (i = 0; i < n3; ++i) {
				printf("%d ", C[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

int IntCmp(const void* a, const void* b)
{
	return *((int*)a) - *((int*)b);
}

int SetDiff(int* A, int n1, int* B, int n2)
{
	int i, j;
	int pos = 0;
	for (i = 0; i < n1; ++i) {
		for (j = 0; j < n2; ++j) {
			if (A[i] == B[j])
				break;
		}
		if (j >= n2) {
			C[pos++] = A[i];
		}
	}
	qsort(C, pos, sizeof(int), IntCmp);
	return pos;
}

