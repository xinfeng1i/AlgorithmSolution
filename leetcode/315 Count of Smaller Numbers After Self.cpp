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

void DivideAndConquer(vector<int>& A, vector<int>& cnt, int left, int right)
{
	// base case
	if (left >= right) return;

	// solve two sub-problems
	int mid = left + (right - left) / 2;
	DivideAndConquer(A, cnt, left, mid);
	DivideAndConquer(A, cnt, mid+1, right);

	// cache the right half and sort
	vector<int> temp(A.begin() + mid + 1, A.begin() + right + 1);
	sort(temp.begin(), temp.end());
	// for each element in the left half, compute the number of elements in the
	// right half with binary search, with time complexity O(nlogn)
	for (int i = left; i <= mid; ++i) {
		auto it = lower_bound(temp.begin(), temp.end(), A[i]);
		cnt[i] += (it - temp.begin());
	}
}


vector<int> countSmaller(vector<int>& A) {
	int n = (int) A.size();
	vector<int> cnt(n, 0);
	DivideAndConquer(A, cnt, 0, n-1);
	return cnt;
}

int main()
{
	int a[] = {5, 2, 6, 1};
	vector<int> v(a, a+4);
	vector<int> ans = countSmaller(v);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}

