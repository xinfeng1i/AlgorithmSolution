#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	// dp[i][j] = choose j pairs integers from the first i elements
	// Then base on the ith is chosen or not, there are two case:
	// not choose ith element, the dp[i][j] = dp[i-1][j]
	// choose ith element, the dp[i][j] = dp[i-m][j-1] + sum(a[i-1]...a[i-m])
	// so dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + sum(a[i-1]...a[i-m])
	// base case: assert (i >= j * m) if not 0 dp[i][j] = 0
	// the problem is equal to find dp[n][k]
	
	vector<vector<long long> > dp(n+1, vector<long long>(k+1, 0));

	// base case
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < k + 1; ++j)
		{
			if (i < j * m)
			{
				dp[i][j] = 0;
			}
		}
	}

	// bottom to up
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < k + 1; ++j)
		{
			if (i >= j * m)
			{
				long long lastPairSum = accumulate(v.begin() + i - m, v.begin() + i, 0LL);
				dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + lastPairSum);	
			}

		}
	}

	long long ans = dp[n][k];
	cout << ans << endl;
	return 0;
}
