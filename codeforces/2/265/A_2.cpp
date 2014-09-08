#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n;
char s[200];
int main()
{
	scanf("%d%s", &n, s);

	int i = 0;
	while (s[i] != '0' && i < n) i++;
	if (i >= n)
	{
		printf("%d\n", n);
	}
	else
	{
		printf("%d\n", i+1);
	}

	return 0;
}
