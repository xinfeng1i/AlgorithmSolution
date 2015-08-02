#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#if 0
int main()
{
	unsigned int n;
	unsigned int s;
	while (scanf("%u", &n) != EOF)
	{
		s = 1;
		for (int i = 1; i <= n - 1; ++i)
		{
			s = (s + 1) * 2;
		}
		printf("%u\n", s);
	}
	return 0;
}
#endif //0