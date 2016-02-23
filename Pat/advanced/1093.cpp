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

#define MOD 1000000007

int main()
{
	string s;
	cin >> s;
	int n = s.size();

	// prefix and suffix array
	vector<int> leftNumberOfP(n, 0);
	vector<int> rightNumberOfT(n, 0);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			if (s[i] == 'P') leftNumberOfP[i] = 1;
			else leftNumberOfP[i] = 0;
		} else {
			if (s[i] == 'P') leftNumberOfP[i] = leftNumberOfP[i-1] + 1;
			else leftNumberOfP[i] = leftNumberOfP[i-1];
		}
	}

	for (int j = n - 1; j >= 0; --j) {
		if (j == n - 1) {
			if (s[j] == 'T') rightNumberOfT[j] = 1;
			else rightNumberOfT[j] = 0;
		} else {
			if (s[j] == 'T') rightNumberOfT[j] = rightNumberOfT[j+1] + 1;
			else rightNumberOfT[j] = rightNumberOfT[j+1];
		}
	}

	// counting PAT
	long long cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			long long leftP = 0;
			if (i - 1 >= 0) leftP = leftNumberOfP[i-1];
			long long rightT = 0;
			if (i + 1 < n) rightT = rightNumberOfT[i+1];
			cnt = (cnt + leftP * rightT) % MOD;
		}
	}
	cout << cnt << endl;
	return 0;
}