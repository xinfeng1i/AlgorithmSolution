#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void swap(char* ch1, char* ch2)
{
	char tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

int main()
{
	char s[10];
	while (scanf("%s", s) != EOF)
	{
		if (s[0] > s[1]) swap(&s[0], &s[1]);
		if (s[0] > s[2]) swap(&s[0], &s[2]);
		if (s[1] > s[2]) swap(&s[1], &s[2]);

		printf("%c %c %c\n", s[0], s[1], s[2]);
	}
	return 0;
}
#endif //0