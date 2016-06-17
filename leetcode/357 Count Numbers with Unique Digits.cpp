#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;


int countNumbersWithUniqueDigits(int n) {
	if (n == 0) return 1;
	if (n == 1) return 10;
	int sum = 10;
	int k = 2;
	int fact = 9 * (11 - k);
	while (k <= n) {
		sum += fact;
		k++;
		fact = fact * (11 - k);
	}
	return sum;
}