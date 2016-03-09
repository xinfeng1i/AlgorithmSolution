#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
using namespace std;

// Dynamic Programming
// Longest Increment Subsequence problem variant
// convert B into A's index is the key

unordered_set<int> ht;
unordered_map<int, int> alice;

void PrintVec(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

void solve2(vector<int>& B)
{
	vector<int> v;
	for (size_t i = 0; i < B.size(); ++i) {
		int t = B[i];
		if (alice.find(t) != alice.end()) {
			v.push_back(alice[t]);
		}
	}

	//PrintVec(v);

	vector<int> dp(v.size(), 1);
	int sz = dp.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (v[i] >= v[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());
	cout << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, L; int t;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<int> A(m, 0);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t);
		A[i] = t;
		alice[t] = i;
		if (ht.find(t) == ht.end()) ht.insert(t);
	}
	scanf("%d", &L);
	vector<int> B(L, 0);
	for (int i = 0; i < L; ++i) {
		scanf("%d", &B[i]);
	}

	/* solution one: my own solution
	// clean the unwanted colors
	vector<int> dp;
	for (int i = 0; i < L; ++i) {
		t = B[i];
		if (ht.find(t) != ht.end())
			dp.push_back(t);
	}

	vector<int> dp2(dp.size(), 1);
	for (int i = 0; i < dp2.size(); ++i) {
		t = dp[i];
		int pos = alice[t];
		for (int j = pos; j >= 0; --j) {
			int elem = A[j];
			for (int k = i - 1; k >= 0; --k) {
				if (dp[k] == elem) {
					dp2[i] = max(dp2[i], dp2[k]+1);
					break;
				}
			}
		}
	}

	//PrintVec(dp2);
	int ans = *max_element(dp2.begin(), dp2.end());
	cout << ans << endl;
	solution one END*/
	
	//solution 2:

	solve2(B);



	return 0;
}