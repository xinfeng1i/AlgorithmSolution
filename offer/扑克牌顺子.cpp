#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;

/*
 * 扑克牌顺子判断
 * 1. 将所有牌排序，计算相邻扑克牌的空缺数，如果空缺数小于等于
 *    零的个数，则说明零可以弥补空缺，形成顺子，否则不行。
 * 2. 注意如果出现对子，则必然不可能是顺子，直接返回
 */
bool IsContinuous(vector<int> numbers) {
    if (numbers.empty()) return false;

	int n = static_cast<int>(numbers.size());
	sort(numbers.begin(), numbers.end());
	int i = 0;
	while (i < n && numbers[i] == 0) i++;
	int n_zero = i;

	//assert(i < n);
	int gap = 0;
	for (int j = i; j < n; ++j) {
		if (j + 1 < n) {
			// equal pairs, cannot be continuous
			if (numbers[j+1] - numbers[j] == 0) {
				return false;
			} else { // count the gaps between two numbers
				gap += numbers[j+1]-numbers[j]-1;
			}
		}
	}

	return gap <= n_zero;
}
