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

// dist[i][j] = the dist between word1[0...i-1] and word2[0...j-1]
// Recursion:
// dist[i][j] = dist[i-1][j-1] + 0 / 1   word1[i-1] == word2[j-1] or not
//            = dist[i-1][j] + 1
//            = dist[i][j-1] + 1
// Init:
// dist[0][j] = j;
// dist[i][0] = i;
// Complexity: O(n1*n2) time & space overhead
int minDistance(string word1, string word2)
{
	int n1 = word1.size();
	int n2 = word2.size();
	vector<vector<int> > dist(n1 + 1, vector<int>(n2 + 1, 0));
	// init
	for (int i = 0; i <= n1; ++i) dist[i][0] = i;
	for (int j = 0; j <= n2; ++j) dist[0][j] = j;

	// bottom to up
	for (int i = 1; i <= n1; ++i)
	{
		for (int j = 1; j <= n2; ++j)
		{
			int tmp = 0;
			if (word1[i-1] == word2[j-1]) tmp = dist[i-1][j-1];
			else tmp = dist[i-1][j-1] + 1;
			
			tmp = min(tmp, dist[i-1][j] + 1);
			tmp = min(tmp, dist[i][j-1] + 1);

			dist[i][j] = tmp;
		}
	}

	return dist[n1][n2];
}