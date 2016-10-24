#include <iostream>
#include <vector>
using namespace std;

int digitSum(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

void visit(vector<vector<int>>& mat, int i, int j, int rows, int cols) {
	if (i < 0 || i >= rows || j < 0 || j >= cols) return;
	if (mat[i][j] == -1) return;

	if (mat[i][j] == 0) {
		mat[i][j] = 1;
		visit(mat, i+1, j, rows, cols);
		visit(mat, i, j+1, rows, cols);
		visit(mat, i-1, j, rows, cols);
		visit(mat, i, j-1, rows, cols);
	}
}


int movingCount(int threshold, int rows, int cols)
{
	vector<vector<int>> mat(rows, vector<int>(cols, 0));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int temp = digitSum(i) + digitSum(j);
			if (temp > threshold) {
				mat[i][j] = -1;
			}
		}
	}
	
	visit(mat, 0, 0, rows, cols);
	
	int ans = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (mat[i][j] == 1) {
				ans++;
			}
		}
	}
	return ans;
}


