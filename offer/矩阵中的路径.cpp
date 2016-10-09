#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

/*
 * 经典回溯问题
 */
bool hasPathRecursion(vector<vector<char>>& m, int i, int j,
    vector<vector<int>>& mark,
    int rows, int cols,
	char* str, int n, int idx) {
	//cout << "i = " << i << " j = " << j;
	//cout << "  idx = " << idx << endl;

	if(idx >= n) return true;
	if (m[i][j] == str[idx] && idx == n-1) return true; // 注意递归终止条件
	if (m[i][j] != str[idx]) return false;
	mark[i][j] = 1;
	if (i+1<rows && mark[i+1][j] == 0) {
		bool ok = hasPathRecursion(m, i+1, j, mark, rows, cols, str, n, idx+1);
		if (ok) return true;
	}
	if (i-1>=0 && mark[i-1][j] == 0) {
		bool ok = hasPathRecursion(m, i-1, j, mark, rows, cols, str, n, idx+1);
		if (ok) return true;
	}
	if (j-1>=0 && mark[i][j-1] == 0) {
		bool ok = hasPathRecursion(m, i, j-1, mark, rows, cols, str, n, idx+1);
		if (ok) return true;
	}
	if (j+1<cols && mark[i][j+1] == 0) {
		bool ok = hasPathRecursion(m, i, j+1, mark, rows, cols, str, n, idx+1);
		if (ok) return true;
	}
	mark[i][j] = 0;
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	vector<vector<char> > m;
	for (int i = 0; i < rows; ++i) {
		vector<char> v;
		for (int j = 0; j < cols; ++j) {
			v.push_back(matrix[i*cols+j]);
		}
		m.push_back(v);
	}
	
	int n = strlen(str);
	vector<vector<int> > mark(rows, vector<int>(cols, 0));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (m[i][j] == str[0]) {
				bool ok = hasPathRecursion(m, i, j, mark, rows, cols, str, n, 0);
				if (ok) return true;
			}
		}
	}
	return false;
}

int main()
{
    char str[] = "AAAAAAAAAAAA";
    cout << hasPath(str, 3, 4, "AAAAAAAAAAAA") << endl;
    return 0;
}
