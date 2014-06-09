#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int row = 1, col = 1, step = 1;
	int s = m * n / k;
	for (int i = 1; i <= k; ++i)
	{
		if (i == k) s += (m * n) % k;

		printf("%d", s);
		for (int j = 0; j < s; ++j)
		{
			printf(" %d %d", row, col);	
			col += step;
			if (col > m) col = m, row += 1, step = -step;
			if (col < 1) col = 1, row += 1, step = -step;
			
		}
		printf("\n");
	}

	return 0;

}
