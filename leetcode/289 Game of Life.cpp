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
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

// [1st bit, 0th bit] = [next_state, current_state]
// 利用位操作实现in-place更新
void gameOfLife(vector<vector<int>>& A) {
	if (A.empty()) return;

	int m = (int) A.size();
	int n = (int) A[0].size();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int live_cnt = 0;
			if (i-1>=0 && j-1>=0) live_cnt += (A[i-1][j-1] & 1);
			if (i-1>=0 && j >= 0) live_cnt += (A[i-1][j] & 1);
			if (i-1>=0 && j+1 <n) live_cnt += (A[i-1][j+1] & 1);
			if (i >= 0 && j-1>=0) live_cnt += (A[i][j-1] & 1);
			if (i >= 0 && j+1 <n) live_cnt += (A[i][j+1] & 1);
			if (i+1< m && j-1>=0) live_cnt += (A[i+1][j-1] & 1);
			if (i+1< m && j >= 0) live_cnt += (A[i+1][j] & 1);
			if (i+1< m && j+1 <n) live_cnt += (A[i+1][j+1] & 1);
			//cout << "i = " << i << "; j = " << j << "; live_cnt=" << live_cnt << endl;

			// live
			if ((A[i][j] & 1) == 1) {
				if (live_cnt < 2 || live_cnt > 3) {;} // next is dead, no need to change
				else { A[i][j] = (A[i][j] ^ 2); } // next is live
			} else {
				// dead
				if (live_cnt == 3) { A[i][j] = (A[i][j] ^ 2); } // next is live
			}


			//cout << "A[i][j] = " << A[i][j] << endl;
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			A[i][j] = (A[i][j] >> 1);
		}
	}
	return;
}

void PrintA(const vector<vector<int>>& A) {
	for (size_t i = 0; i < A.size(); ++i) {
		for (size_t j = 0; j < A[i].size(); ++j) {
			cout << " " << A[i][j];
		}
		cout << endl;
	}
}

int main()
{
	vector<int> v1(2, 1);
	vector<int> v2(2, 1); v2[1] = 0;
	vector<vector<int>> A;
	A.push_back(v1);
	A.push_back(v2);
	gameOfLife(A);
	return 0;
}