#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

#if 0
void PrintVector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	printf("\n");
}

int main() 
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	vector<int> input(n, 0);
	vector<int> output(n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &input[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &output[i]);

	bool isMerge = false;

	int step = 2;
	while (step < n) {
		bool isCurStep = true;
		for (int i = 0; i < n; i += step) {
			int j = min(i + step, n);
			vector<int> temp1(input.begin() + i, input.begin() + j);
			sort(temp1.begin(), temp1.end());

			vector<int> temp2(output.begin() + i, output.begin() + j);
			if (temp1 != temp2) {
				isCurStep = false;
				break;
			}
		}

		if (isCurStep) {
			isMerge = true;
			break;
		} else { 
			step *= 2;
		}
	}


	if (isMerge) {
		printf("Merge Sort\n");
		step *= 2;
		for (int i = 0; i < n; i += step) {
			auto it1 = output.begin() + i;
			int j = min(n, i + step);
			auto it2 = output.begin() + j;
			sort(it1, it2);
		}
		PrintVector(output);
	} else {
		printf("Insertion Sort\n");
		int j = 1;
		while (j < n && output[j] >= output[j-1]) j++;
		int temp = output[j];
		int i = 0;
		while (i < j && output[i] <= temp) i++;
		for (int k = j - 1; k >= i; --k) {
			output[k+1] = output[k];
		}
		output[i] = temp;
		PrintVector(output);
	}
	return 0;
}
#endif // 0