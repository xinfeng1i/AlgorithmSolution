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

void PrintSet(const set<int>& v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (it == v.begin()) cout << *it;
		else cout << " " << *it;
	}
	cout << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	// prefix and suffix array
	vector<int> leftMax(n, 0);
	vector<int> rightMin(n, 0);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			leftMax[i] = v[i];
		} else {
			if (v[i] > leftMax[i-1]) {
				leftMax[i] = v[i];
			} else {
				leftMax[i] = leftMax[i-1];
			}
		} 
	}

	for (int j = n - 1; j >= 0; --j) {
		if (j == n - 1) {
			rightMin[j] = v[j];
		} else {
			if (v[j] < rightMin[j+1]) {
				rightMin[j] = v[j];
			} else {
				rightMin[j] = rightMin[j+1];
			}
		}
	}

	set<int> pivots;
	for (int i = 0; i < n; ++i) {
		bool isPivot = true;
		if (i - 1 >= 0 && v[i] < leftMax[i-1]) isPivot = false;
		if (i + 1 <= n-1 && v[i] > rightMin[i+1]) isPivot = false;
		if (isPivot) {
			pivots.insert(v[i]);
		}
	}

	cout << pivots.size() << endl;
	PrintSet(pivots);

	return 0;
}