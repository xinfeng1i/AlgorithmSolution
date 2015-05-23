#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000 + 5
char s[MAX_N];
char new_str[MAX_N];
long k = 0;

void solve()
{
	memset(new_str, 0, MAX_N);
	memset(s, 0, MAX_N);
	fgets(s, MAX_N, stdin);
	long lastPos = strlen(s) - 1;
	if (s[lastPos] == '\n') s[lastPos] = '\0';
	scanf("%ld\n", &k);
	long n = strlen(s);
	strcpy(new_str, s);
	
	long remainder = n % k;
	long row_num = n / k;
	
	
	long i, j;
	for (j = 0; j < remainder; ++j)
	{
		for (i = 0; i < row_num + 1; ++i)
		{
			new_str[i * k + j] = s[j * (row_num + 1) + i];
		}
	}
	
	for (j = remainder; j < k; ++j)
	{
		for (i = 0; i < row_num; ++i)
		{
			new_str[i * k + j] = s[j * row_num + i + remainder];
		}
	}
		
	printf("%s\n", new_str);
		
}

int main()
{
	//freopen("data.in", "r", stdin);
	
	int T = 0;
	scanf("%d\n", &T);
	int nCase = 0;
	for (nCase = 1; nCase <= T; ++nCase)
	{
		printf("Case #%d:\n", nCase);
		solve();
	}
		
	return 0;
}
