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

// 分层次跳跃， BFS
// 2 3 1 1 4
// 2 || 3 1 || 1 4
// 2所能跳到的位置为3, 1 从3,1 能跳到的位置为1, 4
int jump(vector<int>& nums) {
	int n = (int) nums.size();
	if (n <= 1) return 0;

	int current_max_jump = 0; // 当前所能跳到的最大位置
	int last_max_jump = 0;    // 上一层所能跳到的最大位置
	int step_cnt = 0;         // 跳跃步数

	
	for (int i = 0; i < n - 1; ++i) {
		// 每次更新当前位置所能调大的最大位置
		current_max_jump = max(current_max_jump, nums[i] + i);
		
		// 如果调到了上一层能达到的最大位置，发生一次跳跃
		// 同时跟新上一次所能跳到的最大位置为当前已经遍历过部分所能跳到的最大位置
		if (i == last_max_jump) {
			step_cnt++;
			last_max_jump = current_max_jump;
		}
	}
	return step_cnt;
}

int main()
{
	int a[] = {2, 3, 1, 1, 4};
	vector<int> v(a, a + 5);
	cout << jump(v) << endl;
	return 0;
}