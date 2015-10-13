#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsHuiWen(char* s);
int main()
{
	int i, n;
	char s[1024] = {'\0'};
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", s);
		if (IsHuiWen(s)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

int IsHuiWen(char* s)
{
	int n = strlen(s);
	int i, j;
	for (i = 0, j = n - 1; i < j; i++, j--) {
		if (s[i] != s[j]) return 0;
	}
	return 1;
}
