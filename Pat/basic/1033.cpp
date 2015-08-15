#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;
char brokenKeys[MAX_N];
char str[MAX_N];
char ans[MAX_N];

int main()
{
	//freopen("in.txt", "r", stdin);
	memset(brokenKeys, '\0', MAX_N);
	memset(str, '\0', MAX_N);
	memset(ans, '\0', MAX_N);
	int pos = 0;

	fgets(brokenKeys, MAX_N, stdin);	// 第一行有可能是空行，所以不要用scanf输入
	brokenKeys[strlen(brokenKeys) - 1] = '\0';
	fgets(str, MAX_N, stdin);
	int n1 = strlen(brokenKeys);
	int n2 = strlen(str);

	bool shiftBroken = false;
	if (find(brokenKeys, brokenKeys + n1, '+') != (brokenKeys + n1))
		shiftBroken = true;

	for (int i = 0; i < n2; ++i)
	{
		int ch = str[i];
		if (isalpha(ch))
		{
			if (ch == toupper(ch))
			{
				if (!shiftBroken && find(brokenKeys, brokenKeys + n1, toupper(ch)) == (brokenKeys + n1)) 
					ans[pos++] = ch;
			}
			else
			{
				if (find(brokenKeys, brokenKeys + n1, toupper(ch)) == (brokenKeys + n1)) 
					ans[pos++] = ch;
			}
		}
		else
		{
			if (find(brokenKeys, brokenKeys + n1, ch) == (brokenKeys + n1)) 
				ans[pos++] = ch;
		}
	}

	int n3 = strlen(ans);
	if (n3 == 0) printf("\n");
	else printf("%s", ans); // 注意格式问题

	return 0;
}