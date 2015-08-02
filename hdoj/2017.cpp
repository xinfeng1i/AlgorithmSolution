#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#if 0
char s[10240];

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		cnt = 0;
		memset(s, '\0', 10240);
		scanf("%s", s);
		char* p = s;
		while ((*p) != '\0')
		{
			if (isdigit(*p)) cnt++;
			p++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#endif //0