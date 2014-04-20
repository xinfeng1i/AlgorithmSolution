#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[50000+5][5+5];
int t;

/**
 * DP problem:
 * 
 * dp[i][j] = the time when the ith picture done by the jth painter 
 * then 
 * dp[i][j] = max(dp[i-1][j] + t, dp[i][j-1] + t)
 * initial condition
 * dp[0][j] = {0};
 * dp[i][0] = {0};
 *
 */

int main()
{
	long m, n;
	cin >> m >> n;

	
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> t;
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + t;
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		cout << " " << dp[i][n];
	}
	cout << endl;

	return 0;

}
