#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountYuanYin(const char* s, int* cnt);

int main()
{
	int n;
	int i, j;
	char line[256];
	int cnt[5] = { 0 };
	
	scanf("%d\n", &n);
	for (i = 0; i < n; ++i) {
		gets(line);
		CountYuanYin(line, cnt);
		printf("a:%d\n", cnt[0]);
		printf("e:%d\n", cnt[1]);
		printf("i:%d\n", cnt[2]);
		printf("o:%d\n", cnt[3]);
		printf("u:%d\n", cnt[4]);
		if (i != n - 1) printf("\n");
	}
	return 0;
}

void CountYuanYin(const char* s, int* cnt)
{
	int i, n;
	for (i = 0; i < 5; ++i) cnt[i] = 0;
	n = strlen(s);
	for (i = 0; i < n; ++i) {
		switch(s[i]) {
			case 'a': cnt[0]++; break;
			case 'e': cnt[1]++; break;
			case 'i': cnt[2]++; break;
			case 'o': cnt[3]++; break;
			case 'u': cnt[4]++; break;
			default: break;
		}
	}
	return;
}
