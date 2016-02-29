#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 1
int main()
{
	freopen("input.txt", "r", stdin);
	int n = -1;
	scanf("%d", &n);

	double num = 0.0;
	double sum = 0.0;

	int coef = n;
	int nTerms = 1;
	while (coef >= 1) {
		scanf("%lf", &num);
		// cast [int] to [double] to avoid int overflow 
		sum += (double)coef * (double)nTerms * num;
		coef -= 1;
		nTerms += 1;
	}
	printf("%.2lf\n", sum);
	return 0;
}
#endif //0