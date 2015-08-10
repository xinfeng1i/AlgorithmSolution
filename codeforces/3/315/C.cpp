#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

typedef unsigned int uint;
char tmp[100];

bool IsPrime(uint n)
{
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool IsPalindrome(uint n)
{
	memset(tmp, '\0', 100);
	sprintf(tmp, "%u", n);
	int sz = strlen(tmp);
	for (int i = 0, j = sz - 1; i < j; i++, j--)
	{
		if (tmp[i] != tmp[j]) return false;
	}
	return true;
}

int main()
{
	uint q = 0, p = 0;
	scanf("%u %u", &p, &q);

	uint n = 1;
	uint cnt1 = 0;
	uint cnt2 = 0;

	while (n < 10000)
	{
		if (IsPrime(n)) cnt1++;
		if (IsPalindrome(n)) cnt2++;
		//cout << n << " " << q * cnt1 << " " << p * cnt2 << endl;

		cout << n << " " << cnt1 << " " << cnt2;
		cout << " " << (double)cnt1 / cnt2 << endl;

		//if (q * cnt1 > p * cnt2) break;
		n++;
	}

	if (n == 1) printf("Palindromic tree is better than splay tree\n");
	else printf("ans: %u\n", n - 1);

	return 0;
}