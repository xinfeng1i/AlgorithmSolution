#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 数组逆序：归并
 * 1. 递归处理左右两个半数组，递归终止为只有1个元素的情况
 * 2. 归并的过程中计算跨越两个半数组的逆序对
 * 3. 注意MOD的整型溢出情况
 */
const int MOD = 1000000007;
int InversePairsRecursion(vector<int>& A, int lo, int hi) {
	//cout << " here : lo = " << lo << " hi = " << hi << endl;
	if (lo >= hi) return 0;
	int mid = lo + (hi - lo)/2;
	int cnt1 = InversePairsRecursion(A, lo, mid);
	int cnt2 = InversePairsRecursion(A, mid+1, hi);
	int temp_sum = (cnt1 % MOD + cnt2 % MOD) % MOD;

	int i = mid;
	int j = hi;
	int cnt = 0;
	while (i >= lo) {
		while (j >= mid+1 && A[j] >= A[i]) {
			j--;
		}
		if (j < mid+1) break;
		cnt = (cnt % MOD + (j-mid)%MOD)%MOD;
		i--;
	}

	sort(A.begin()+lo, A.begin()+hi+1);
	return (cnt+temp_sum)%MOD;
}

int InversePairs(vector<int> A) {
	int n = static_cast<int>(A.size());
	return InversePairsRecursion(A, 0, n-1);
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 0};
	cout << InversePairs(v) << endl;
	return 0;
}
