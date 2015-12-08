#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	double ans = 0.0;
	double num;
	long long i = 1;
	for (; i <= n; ++i) {
		scanf("%lf", &num);
		ans += num * (i * (n + 1 - i));
	}
	printf("%.2lf\n", ans);
	return 0;
}
