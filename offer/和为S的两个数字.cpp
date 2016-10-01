#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 经典二分查找问题
 */
vector<int> FindNumbersWithSum(vector<int> A,int sum) {
	int n = static_cast<int>(A.size());
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int x = A[i];
		int y = sum - x;
		bool ok = std::binary_search(A.begin()+i+1, A.end(), y);
		if (ok) {
			ans.push_back(x);
			ans.push_back(y);
			return ans;
		}
	}
	return ans;
}
