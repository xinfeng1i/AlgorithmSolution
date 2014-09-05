#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end(), greater<int>());

	vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
	deque<deque<bool> > visited(n+1, deque<bool>(k+1, false));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j >= v[i-1])
			{
				int tmp1 = dp[i-1][j-v[i-1]] + v[i-1];
				int tmp2 = dp[i-1][j];
				if (tmp1 >= tmp2)
				{
					dp[i][j] = tmp1;
					visited[i][j] = true;
				}
				else
				{
					dp[i][j] = tmp2;
				}
				
			}
			else
			{
				int tmp = dp[i-1][j];
				dp[i][j] = tmp;
			}
		}
	}

	if (dp[n][k] == k)
	{
		int m = k;
		int i = n;
		bool flag = true;
		while (m > 0)
		{
			while (!visited[i][m]) i--;
			if (flag) { cout << v[i-1]; flag = false;}
			else {cout << " " << v[i-1];}
			m -= v[i-1];
			i--;

		}
		cout << endl;
	}
	else
	{
		cout << "No Solution" << endl;
	}
	return 0;
}

/*
 * Summary: DP problem
 * Tricky: track the choice is the key of the problem
 *         sort the array decreasing is necessary to track the choice
 *         Others is like the coins change problem
 */
