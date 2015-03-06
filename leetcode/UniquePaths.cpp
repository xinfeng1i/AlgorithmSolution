#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Define: cnt[i][j] = the number of unique paths from(1,1) to (i,j)
// Recursion:
// cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
// Init:
// cnt[1][j] = 1;
// cnt[i][1] = 1;
// Complexity: O(mn) space & time overhead
int uniquePaths(int m, int n)
{
	vector<vector<int> > cnt(m+1, vector<int>(n+1, 0));
	// init
	for (int i = 0; i <= m; ++i) cnt[i][1] = 1;
	for (int j = 0; j <= n; ++j) cnt[1][j] = 1;
	// bottom to up
	for (int i = 2; i <= m; ++i)
	{
		for (int j = 2; j <= n; ++j)
		{
			cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
		}
	}

	return cnt[m][n];
}