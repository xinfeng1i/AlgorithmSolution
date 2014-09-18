#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

void PrintVector(const vector<vector<long> >& v)
{
	int n = v.size();
	int m = v[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

const long INF = -LONG_MAX;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<long> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	// dp[i][j] = choose j pair ints from the first i elements whose sum is maximal
	// dp[i][k] = dp[j][k-1], j >= (k-1) * m && j <= n;
	// base case: dp[j][0] = 0; dp[0][k] = 0;
	vector<vector<long> > dp(n+1, vector<long>((k+1), INF));
	for (int j = 0; j <= k; ++j)
	{
		dp[0][j] = 0;
	}
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 0;
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j * m > i) continue;

			long curmax = 0;
			for (int k2 = i-m; k2 >= (j-1)*m; --k2)
			{
				long cursum = accumulate(v.begin() + k2, v.begin() + k2 + m, 0L); 
				if (cursum + dp[k2][j-1]  > curmax)
				{
					curmax = cursum + dp[k2][j-1];
				}
			}

			dp[i][j] = curmax;
		}
	}

	//PrintVector(dp);

	int ans = dp[n][k];
	cout << ans << endl;
	return 0;	
}
