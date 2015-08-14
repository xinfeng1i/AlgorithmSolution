#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const int MOD = 11;
const char M[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int invalid_num = 0;
	for (int i = 0; i < n; ++i)
	{
		char ID[20];
		bool valid = true;
		scanf("%s", ID);
		int len = strlen(ID);
		int sum = 0;

		for (int j = 0; j < len - 1; ++j)
		{
			if (!isdigit(ID[j]))
			{
				valid = false;
				break;
			}
			else
			{
				sum += weight[j] * (ID[j] - '0');
			}
		}

		if (valid)
		{
			int idx = sum % MOD;
			if (M[idx] != ID[len - 1]) valid = false;
		}

		if (!valid)
		{
			invalid_num++;
			printf("%s\n", ID);
		}
	}

	if (invalid_num == 0)
	{
		printf("All passed\n");
	}
	return 0;
}
