#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

/* O(n^2) brute-force algo, not efficiently
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i + 1 < n; ++i) {
    	for (int j = 0; j < n - 1 - i; ++j) {
        	if (nums[j] != 0) {
            	continue;
        	} else {
        		swap(nums[j], nums[j+1]);
        	}
        	
        }
    }
}
*/

/**
 * O(n) algorithm
 * Loop Invariant: (-INF, i] != 0 && [i+1, j) == 0
 * Initial: satisfied
 * After every loop: satisfied
 * Then: algorithm is right
 */
void moveZeroes(vector<int>& nums){
	int n = nums.size();
	int i = -1;
	for (int j = 0; j < n; ++j) {
		if (nums[j] != 0) {
			i += 1;
			swap(nums[i], nums[j]);
		} else {
			continue;
		}
	}
}

int main()
{
	int a[] = {0, 1, 0, 2, 3};
	vector<int> v(a, a + 5);
	moveZeroes(v);
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
	
	return 0;
}
