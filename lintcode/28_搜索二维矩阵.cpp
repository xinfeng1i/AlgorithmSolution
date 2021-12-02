#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;


bool searchMatrix(vector<vector<int>>& mat, int target) {
	if (mat.empty()) return false;

	int m = mat.size();
	int n = mat[0].size();

	// 找到第一个大于目标元素的行
	int up = 0;
	int down = m - 1;
	while (up < down) {
		int mid = up + (down - up) / 2;
		if (mat[mid][0] == target) {
			return true;
		}
		else if (mat[mid][0] < target) {
			up = mid + 1;
		}
		else {
			down = mid;
		}
	}

	// we have up == down, then target must lies in <up-1> row
	int row = up - 1 >= 0 ? up - 1 : 0;
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (mat[row][mid] == target) {
			return true;
		}
		else if (mat[row][mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return mat[row][left] == target ? true : false;
}

int main() {
	vector<int> row1 = { 5 };

	vector<vector<int>> mat;
	mat.push_back(row1);

	bool flag = searchMatrix(mat, 2);
	cout << flag << endl;

	vector<int> r1 = { 1, 3, 5, 7 };
	vector<int> r2 = { 10, 11, 16, 20 };
	vector<int> r3 = { 23, 30, 34, 50 };
	vector<vector<int>> m;
	m.push_back(r1);
	m.push_back(r2);
	m.push_back(r3);

	bool flag2 = searchMatrix(m, 3);
	cout << flag2 << endl;

	return 0;
}