#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char s[1000];
char tmp[1000];

int main()
{
	while (scanf("%s", s) != EOF)
	{
		int len = strlen(s);
		char max = s[0];
		for (int j = 1; j < len; ++j)
		{
			if (s[j] > max)
			{
				max = s[j];
			}
		}

		memset(tmp, '\0', 1000);
		char* p = tmp;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] != max)
			{
				*p = s[i];
				p++;
			}
			else
			{
				*p = s[i];
				*(p + 1) = '(';
				*(p + 2) = 'm';
				*(p + 3) = 'a';
				*(p + 4) = 'x';
				*(p + 5) = ')';
				p = p + 6;
			}
		}
		printf("%s\n", tmp);
	}
	return 0;
}