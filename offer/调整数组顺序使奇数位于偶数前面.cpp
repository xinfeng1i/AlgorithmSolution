#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * 空间换时间，在O(n)的时间内先将所有的奇数取出
 * 然后将所有偶数取出，即可
 * O(n) 时间 O(n) 空间
 */

void reOrderArray(vector<int> &array) {
	int n = static_cast<int>(array.size());
	vector<int> ans;
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] % 2 == 1) ans.push_back(array[i]);
	}
	
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] % 2 == 0) ans.push_back(array[i]);
	}
	array = ans;
	return;
}
