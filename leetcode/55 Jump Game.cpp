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
using namespace std;

// 贪心算法
// 如果能到k位置，则必然能到k前面的位置
bool canJump(vector<int>& nums) {
	int n = (int)nums.size();
	
	int cur = 0; // 当前位置
	int maxCanReach = cur + nums[cur]; // 当前所能到达的最大位置
	while (cur < n && cur <= maxCanReach) { // 对于没能到达的每一个位置遍历
		maxCanReach = max(cur + nums[cur], maxCanReach); // 更新最大位置
		cur++;
	}
	return maxCanReach>=n-1;
}


#if 0
int main()
{
	int a[] = {2, 3, 1, 1, 4};
	int b[] = {3, 2, 1, 0, 4};
	vector<int> v1(a, a + 5);
	vector<int> v2(b, b + 5);

	cout << canJump(v1) << endl;
	cout << canJump(v2) << endl;
	
	return 0;
}
#endif //