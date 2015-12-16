#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/**
 * Insert Sorting
 * INPUT: an array [a0, a1, ..., a(n-1)]
 * OUTPUT: an in-place sorted array 
 *
 * Loop Invariant: [0, j-1] is sorted and [j, n-1] is to be sorting
 *
 * Correctness Proof:
 * Initialization: [0, 0] is sorted
 * Maintenance: suppose [0, j-1] is sorted, after one loop [0, j] is sorted
 * Termination: when the loop ends, j = n, indicting that [0, n-1] has been sorted
 */
void InsertSort(vector<int>& nums) {
	int n = nums.size();
	for (int j = 1; j < n; ++j) {
		int x = nums[j];
		int i = j - 1;
		while (i >= 0 && nums[i] > x) {
			nums[i+1] = nums[i];
			i -= 1;
		}
		nums[i+1] = x;
	}
}

void PrintVector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
}

int main()
{
	int a[] = {2, 1, 3, 4, 5};
	vector<int> v(a, a + 5);
	random_shuffle(v.begin(), v.end());
	cout << "Original Array: " << endl;
	PrintVector(v);

	InsertSort(v);

	cout << "After Sorting Array:" << endl;
	PrintVector(v);

	return 0;
}
