#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;


/*
 * Method1: ˫ָ�뻬�����ڣ���ָ�벻�����󴰿ڣ���ָ�벻����������
 * ʱ�临�Ӷȣ�O(n)
 * �ռ临�Ӷȣ�O(1)
 */
int longestOnes(vector<int>& nums, int k) {
	int ans = 0;
	int n = (int)nums.size();

	int i = 0;
	int j = 0;
	int remain = k;
	while (i < n) {
		// �����Ҳര��
		while (j < n) {
			if (nums[j] == 1) {
				j++;
			} else if (remain > 0) {
				j++;
				remain--;
			} else {
				break;
			}
		}
		ans = max(ans, j - i);

		// ��С��ര��
		while (i < n && nums[i] == 1) i++;
		if (i >= n) break;
		i += 1;
		remain++;
	}

	return ans;
}

#if 0
int main() {
	// expected: 6
	vector<int> v1 = { 1,1,1,0,0,0,1,1,1,1,0 };
	int k1 = 2;
	int ans1 = longestOnes(v1, k1);
	printf("%d\n", ans1);


	// expected: 10
	vector<int> v2 = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
	int k2 = 3;
	int ans2 = longestOnes(v2, k2);

	printf("%d\n", ans2);

	return 0;
}
#endif // 0