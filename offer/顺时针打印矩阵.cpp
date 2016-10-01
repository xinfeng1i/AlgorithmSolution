#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * 模拟顺时针打印矩阵
 * 1. 注意只有一行的特殊例子
 * 2. 注意只有一列的特殊例子
 */
vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> ans;
	if (matrix.empty()) return ans;
	int m = static_cast<int>(matrix.size());
	int n = static_cast<int>(matrix[0].size());
	int start_row = 0;
	int start_col = 0;
	int end_row = m - 1;
	int end_col = n - 1;
	
	while (start_row <= end_row && start_col <= end_col) {
		for (int j = start_col; j <= end_col; ++j) ans.push_back(matrix[start_row][j]);
		for (int i = start_row+1; i <= end_row; ++i) ans.push_back(matrix[i][end_col]);
		if (start_row < end_row) {
		   for (int j = end_col-1; j >= start_col; --j) ans.push_back(matrix[end_row][j]);
		}
		if (start_col < end_col) {
		   for (int i = end_row-1; i >= start_row+1; --i) ans.push_back(matrix[i][start_col]);
		}
		start_row += 1;
		start_col += 1;
		end_row -= 1;
		end_col -= 1;
	}
	return ans;
}
