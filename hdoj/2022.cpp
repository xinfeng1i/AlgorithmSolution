#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
int main()
{
	int m, n;
	int x, y, s;
	int tmp;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		x = 0;
		y = 0;
		s = 0;
		int found = 0;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				scanf("%d", &tmp);
				if (x == 0 && y == 0)
				{
					x = i;
					y = j;
					s = tmp;
				}

				if (tmp == -2147483648)
				{
					x = i;
					y = j;
					s = tmp;
					found = 1;
					break;
				}
				else
				{
					if (abs(tmp) > abs(s))
					{
						x = i;
						y = j;
						s = tmp;
					}
					else if (abs(tmp) == abs(s))
					{
						if (i < x)
						{
							x = i;
							y = j;
							s = tmp;
						}
						else if (i == x)
						{
							if (j < y)
							{
								x = i;
								y = j;
								s = tmp;
							}
						}
					}
				}
			}

			if (found == 1) break;
		}

		printf("%d %d %d\n", x, y, s);

	}
	return 0;

}
#endif //0