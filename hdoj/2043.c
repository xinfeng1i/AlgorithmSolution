#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[255];

int IsSafePwd(char* s);

int main()
{
	int i, n, len;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", str);
		if (IsSafePwd(str))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int IsSafePwd(char* s)
{
	int t1, t2, t3, t4;
	int i, n;
	t1 = t2 = t3 = t4 = 0;
	n = strlen(s);
	if (n < 8 || n > 16) return 0;
	for (i = 0; i < n; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') t1 = 1;
		if (s[i] >= 'a' && s[i] <= 'z') t2 = 1;
		if (s[i] >= '0' && s[i] <= '9') t3 = 1;
		if (s[i] == '~' || s[i] == '!' || s[i] == '@' ||
			s[i] == '#' || s[i] == '$' || s[i] == '%' ||
			s[i] == '^')
			t4 = 1;
	}
	return (t1 + t2 + t3 + t4) >= 3;
}
