#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
	if (A.size() <= 1) return false;

	set<int> windows;
	int n = (int) A.size();
	for (int j = 0; j < n; ++j) {
		// auto it = lower_bound(windows.begin(), windows.end(), A[j]-t);
		auto it = windows.lower_bound(A[j]-t);
		if (it != windows.end() && *it - A[j] <= t) {
			return true;
		}

		windows.insert(A[j]);
		if (j-k>=0 && windows.size() > k) {
			windows.erase(A[j-k]);
		}
	}
	return false;

}

int main()
{
	int a[] = {0, 2147483647};
    vector<int> A(a, a+2);
	int k = 1;
	int t = 2147483647;
	cout << containsNearbyAlmostDuplicate(A, k, t) << endl;
	return 0;
}