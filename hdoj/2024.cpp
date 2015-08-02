#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
char s[55];

int main()
{
	int n;
	while (scanf("%d\n", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			memset(s, '\0', 55);
			fgets(s, 55, stdin);
			s[strlen(s) - 1] = '\0';
			int len = strlen(s);
			int ok = 1;
			for (int j = 0; j < len; ++j)
			{
				if (j == 0)
				{
					if (!(isalpha(s[j]) || s[j] == '_'))
						ok = 0;
				}
				else
				{
					if (!(isdigit(s[j]) || isalpha(s[j]) || s[j] == '_'))
						ok = 0;
				}
			}
			if (ok) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
#endif //0

// 总结：
// 1. fgets 会把 \n 也都进字符串，因此需要 s [strlen(s)-1] = '\0'消去  '\n'
// 2. gets 会把 \n 自动替换为 '\0'