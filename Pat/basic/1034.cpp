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

typedef long long llong;

llong gcd(llong a, llong b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void PrintNum(llong a, llong b)
{
	if (abs(a) == 0)
	{
		printf("0");
		return;
	}

	llong g = gcd(abs(a), abs(b));
	a /= g;
	b /= g;

	if (b < 0)
	{
		b *= -1;
		a *= -1;
	}

	if (abs(a) >= abs(b))
	{
		if (abs(a) % abs(b) == 0)
		{
			llong k = a / b;
			if (k < 0) printf("(%lld)", k);
			else printf("%lld", k);
		}
		else
		{
			llong k = a / b;
			a = abs(a) % b;
			if (k < 0) printf("(%lld %lld/%lld)", k, a, b);
			else printf("%lld %lld/%lld", k, a, b);
		}
	}
	else
	{
		if (a < 0) printf("(%lld/%lld)", a, b);
		else printf("%lld/%lld", a, b);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	llong a1 = 0; llong b1 = 0;
	llong a2 = 0; llong b2 = 0;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	llong sum_a = a1 * b2 + a2 * b1;
	llong sum_b = b1 * b2;
	PrintNum(a1, b1);
	printf(" + ");
	PrintNum(a2, b2);
	printf(" = ");
	PrintNum(sum_a, sum_b);
	printf("\n");

	llong sub_a = a1 * b2 - a2 * b1;
	llong sub_b = b1 * b2;
	PrintNum(a1, b1);
	printf(" - ");
	PrintNum(a2, b2);
	printf(" = ");
	PrintNum(sub_a, sub_b);
	printf("\n");

	llong mul_a = a1 * a2;
	llong mul_b = b1 * b2;
	PrintNum(a1, b1);
	printf(" * ");
	PrintNum(a2, b2);
	printf(" = ");
	PrintNum(mul_a, mul_b);
	printf("\n");

	if (abs(a2) == 0)
	{
		PrintNum(a1, b1);
		printf(" / ");
		PrintNum(a2, b2);
		printf(" = ");
		printf("Inf\n");
	}
	else
	{
		llong div_a = a1 * b2;
		llong div_b = a2 * b1;
		PrintNum(a1, b1);
		printf(" / ");
		PrintNum(a2, b2);
		printf(" = ");
		PrintNum(div_a, div_b);
		printf("\n");
	}

	return 0;
}

// 使用 int 会发生整型溢出，改用 long long, AC