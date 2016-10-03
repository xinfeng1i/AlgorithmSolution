#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 用堆处理最小的K个数问题
 * 注意边界条件：数组中少于k个数，返回空
 */
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	if (static_cast<int>(input.size()) < k) return vector<int>();
	set<int, greater<int>> heap;
	for (size_t i = 0; i < input.size(); ++i) {
		if (heap.size() < k) {
			heap.insert(input[i]);
		} else if (heap.size() == k) {
			int temp = *heap.begin();
			if (input[i] < temp) {
				heap.erase(temp);
				heap.insert(input[i]);
			}
		}
	}
	return vector<int>(heap.rbegin(), heap.rend());
}

int main()
{
	vector<int> v = {4,5,1,6,2,7,3,8};
	vector<int> ans = GetLeastNumbers_Solution(v, 4);
	for (size_t i = 0; i < ans.size(); ++i)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
