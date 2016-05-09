#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
using namespace std;


void CombinationRecursion(const vector<int>& A, int left, int right, int k,
    vector<int>& current, vector<vector<int> >& ans) {

	//assert(right-left+1>=k);
	if (k == 0) {
	    ans.push_back(current);
	    return;
    }
	
	for (int i = left; i <= right; ++i) {
		int x = A[i];
		current.push_back(x);
		CombinationRecursion(A, i+1, right, k-1, current, ans);
		current.pop_back();
	}
	return;
}


vector<vector<int> > combine(int n, int k) {
	assert(k <= n);

	vector<int> A(n, 0);
	for (int i = 0; i < n; ++i) A[i] = i + 1;
	
    vector<int> current;
    vector<vector<int> > ans;
	CombinationRecursion(A, 0, n-1, k, current, ans);
	
	return ans;
}

int main()
{
	vector<vector<int> > ans = combine(4, 2);
	for (size_t i = 0; i < ans.size(); ++i) {
		for (size_t j = 0; j < ans[i].size(); ++j) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
