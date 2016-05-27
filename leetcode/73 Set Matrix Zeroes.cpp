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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

#if 0
// 方法一：naive算法，使用O(mn)的空间
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
       
    vector<vector<bool>> A(m, vector<bool>(n, true));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = matrix[i][j];
        }
    }
       
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!A[i][j]) {
                for (int jj = 0; jj < n; ++jj) matrix[i][jj] = 0;
                for (int ii = 0; ii < m; ++ii) matrix[ii][j] = 0;
            }
        }
    }
       
    return;
}
#endif //0


// 方法二：参考hot votes答案，在O(1)空间内解决
void setZeroes(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;

	int m = (int) matrix.size();
	int n = (int) matrix[0].size();
	// use the first row and col as marks to mark the zero rows and zero cols
	int col0 = 1;
	for (int i = 0; i < m; ++i) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < n; ++j) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (int i = m - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 1; --j) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
		// the first column is marked with variable col0
		if (col0 == 0) matrix[i][0] = 0;
	}

	return;
}