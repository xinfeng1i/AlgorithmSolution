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

int calculateMinimumHP(vector<vector<int>>& board) {
	int m = int(board.size());
	int n = int(board[0].size());
	// add dummy row and column at bottom and right
	// then calculate from bottom right to up left
	vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
	dp[m][n-1] = 1;
	dp[m-1][n] = 1;
	for (int i = m-1; i >= 0; --i) {
		for (int j = n-1; j >= 0; --j) {
			int need = min(dp[i][j+1], dp[i+1][j]) - board[i][j];
			dp[i][j] = need > 0 ? need : 1;
		}
	}
	return dp[0][0];
}

#if 0
int main()
{
	int a1[] = {-2, -3, 3};
	int a2[] = {-5, -10, 1};
	int a3[] = {10, 30, -5};
	vector<int> v1(a1, a1+3);
	vector<int> v2(a2, a2+3);
	vector<int> v3(a3, a3+3);
	vector<vector<int>> A;
	A.push_back(v1);
	A.push_back(v2);
	A.push_back(v3);
	cout << calculateMinimumHP(A) << endl;
	return 0;
}
#endif //0