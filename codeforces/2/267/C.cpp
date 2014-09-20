#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> v(n, 0);
	vector<long long> sum(n+1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sum[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		sum[i] = sum[i-1] + v[i-1];
	}

	// dp[i][j] = choose j pair ints from the first i elements whose sum is maximal
	// dp[i][k] = dp[j][k-1], j >= (k-1) * m && j <= n;
	// base case: dp[j][0] = 0; dp[0][k] = 0;
	vector<vector<long long> > dp(n+1, vector<long long>((k+1), 0LL));
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

			long long curmax = 0;
			for (int k2 = i-m; k2 >= (j-1)*m; --k2)
			{
				long long cursum = sum[k2+m] - sum[k2];  
				if (cursum + dp[k2][j-1]  > curmax)
				{
					curmax = cursum + dp[k2][j-1];
				}
			}

			dp[i][j] = curmax;
		}
	}


	long long ans = dp[n][k];
	cout << ans << endl;
	return 0;	
}
