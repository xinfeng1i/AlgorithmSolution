#include <stdio.h>
#include <stdlib.h>

int f(int ch);

int main()
{
	int T, i;
	int ch; long long y;
	scanf("%d\n", &T);
	for (i = 0; i < T; ++i) {
		scanf("%c %lld", &ch, &y);
		getchar();
		y += f(ch);
		printf("%lld\n", y);
	}
	return 0;
}

int f(int ch)
{
	if (ch >= 'a' && ch <= 'z') return -(ch-'a'+1);
	if (ch >= 'A' && ch <= 'Z') return (ch-'A'+1);
}
