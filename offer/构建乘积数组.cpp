#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

/*
 * 经典问题：使用前缀后缀数组
 */
vector<int> multiply(const vector<int>& A) {
	vector<int> ans;
	if (A.empty()) return ans;
	
	int n = static_cast<int>(A.size());
	vector<int> prefix(n, 0);
	prefix[0] = A[0];
	for (int i = 1; i < n; ++i) {
		prefix[i] = prefix[i-1] * A[i];
	}
	
	vector<int> suffix(n, 0);
	suffix[n-1] = A[n-1];
	for (int i = n-2; i >= 0; --i) {
		suffix[i] = suffix[i+1] * A[i];
	}
	
	ans.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			ans[i] = i+1<n ? suffix[i+1] : 1;
		} else if (i == n-1) {
			ans[i] = i-1>=0 ? prefix[i-1] : 1;
		} else {
			ans[i] = prefix[i-1] * suffix[i+1];
		}
	}
	
	return ans;
}

int main()
{
	vector<int> A = {10, 20, 30};
	vector<int> ans = multiply(A);
	for (auto x : ans) cout << x << endl;
	return 0;
}
