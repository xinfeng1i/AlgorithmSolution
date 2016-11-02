#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
 * 计算以当前bar为最短边的矩形的面积，如果遍历过所有bar后，
 * 那么我们就可以得到所有面积的最大值
 *
 * 因此我们需要知道左边比当前bar小的bar的位置和右边比当前bar
 * 小的第一个bar的位置，如何知道这两个位置呢？如果当前元素比栈顶
 * 元素大，则push，否则pop出栈顶元素tp，并且计算以tp为最低bar的面积
 * 那么以tp为最低bar的左右更低索引分别是当前索引i和栈内的前一个索引
 */
int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	stack<int> S;
	
	int max_area = 0;
	int i = 0;
	while (i < n) {
		if (S.empty() || heights[i] >= heights[S.top()]) {
			S.push(i);
			i++;
		} else {
			int tp = S.top(); S.pop();
			int left_idx = S.empty() ? -1 : S.top();
			int local_area = (i-left_idx-1) * heights[tp];
			max_area = max(max_area, local_area);
		}
	}
	
	while (!S.empty()) {
		int tp = S.top(); S.pop();
		int left_idx = S.empty() ? -1 : S.top();
		int local_area = (i-left_idx-1) * heights[tp];
		max_area = max(max_area, local_area);
	}
	
	return max_area;
}

int main()
{
	int a[] = {2,1,5,6,2,3};
	//int a[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(a) / sizeof(a[0]);
	
	vector<int> v(a, a+n);
	cout << "vector" << endl;
	for (size_t i = 0; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
	cout << largestRectangleArea(v) << endl;
	return 0;
}
