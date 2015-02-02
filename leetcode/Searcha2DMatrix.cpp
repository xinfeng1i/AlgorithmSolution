#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) 
{
	int m = matrix.size();
	int n = matrix[0].size();

	vector<int> tmp;
	tmp.reserve(m*n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmp.push_back(matrix[i][j]);
		}
	}

	bool ans = binary_search(tmp.begin(), tmp.end(), target);
	return ans;
}
