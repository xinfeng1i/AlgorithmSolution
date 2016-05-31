#include <vector>
#include <set>
#include <iostream>
#include <string>
using namespace std;

// Greedy:
// MaxCanReach record current max number we can reach
// For example, maxCanReach = 6 means that we can obtain [1,2,3,4,5,6]
// then we check the next number in the array, if it in [1, maxCanReach+1]
// then we just expand our maxcanReach
// For example, if next number is 4, then we can now reach max 10 (6+4)
// if next number is 7, we also do not need to add any number, we can reach now
// 13 (6+7)
// if next number is not in [1, maxCanReach], we need to add patches,
// For example, next number is 8, then we need to add a patch number 7, and extend
// the maxCanReach to be 13 (6+7)

int minPatches(vector<int>& A, int n) {
	long long maxCanReach = 0; // avoid INT_MAX overflow
	int cnt = 0;
	size_t i = 0;
	while (maxCanReach < n) {
		if (i < A.size() && A[i] <= maxCanReach+1) {
			maxCanReach += A[i];
			i++;
		} else {
			cnt++;
			maxCanReach += (maxCanReach + 1);
		}
	}
	return cnt;
}

int main() {
	int a[] = {1, 2, 2, 33};
	vector<int> A(a, a + 3);

	int n = 5;
	cout << minPatches(A, n) << endl;
	
	return 0;
}
