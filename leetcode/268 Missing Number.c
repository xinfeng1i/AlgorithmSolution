#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize)
{
	int sum = 0;
	int i;
	for (i = 0; i < numsSize; ++i) sum += nums[i];
	int tot = (1 + numsSize) * numsSize / 2;
	return tot - sum;
}

int main()
{
	int a[] = {0, 1, 3};
	printf("%d\n", missingNumber(a, 3));
	return 0;
}
