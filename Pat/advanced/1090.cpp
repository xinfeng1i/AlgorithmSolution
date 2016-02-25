#include <iostream>
#include <vector>
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

#if 0
unordered_map<int, int> gDist;

int GetPathLength(int dest, const vector<int>& prev) {
	if (gDist.find(dest) != gDist.end()) {
		return gDist[dest];
	} else {
		if (prev[dest] == -1) {
			gDist[dest] = 1;
			return 1;
		} else {
			int temp = GetPathLength(prev[dest], prev) + 1;
			gDist[dest] = temp;
			return temp;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	double price, rate;
	cin >> n >> price >> rate;
	rate = rate / 100.0;

	vector<int> prev(n, -1);
	for (int i = 0; i < n; ++i) cin >> prev[i];

	int longestLength = 0;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int length = GetPathLength(i, prev);
		if (length > longestLength) {
			longestLength = length;
			count = 1;
		} else if (length == longestLength) {
			count += 1;
		}
	}

	double finalPrice = price * pow((1+rate), double(longestLength-1));
	printf("%.2lf %d\n", finalPrice, count);

	return 0;
}
#endif //0