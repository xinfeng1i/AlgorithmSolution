#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

long long n, d;


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> d;

	vector<long long> v(n);
	vector<long long> dp(n, 1);
	vector<long long> prev(n, -1);

	for (long long i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	
	for (long long i = 1; i < n; ++i)
	{
		// shorten the search range with 700, but why?
		for (long long j = max(0LL, i-700); j < i; ++j)
		{
			if (abs(v[j] - v[i]) >= d)
			{
				if (dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
					prev[i] = j;
				}
			}
		}
	}

	long long ans = 0;
	long long ansindex = -1;
	for (long long i = 0; i < n; ++i)
	{
		if (dp[i] > ans)
		{
			ans = dp[i];
			ansindex = i;
		}
	}

	cout << ans << endl;
	stack<long long> myans;
	while (ansindex != -1)
	{
		//cout << ansindex << " ";
		myans.push(ansindex);	
		ansindex = prev[ansindex];
	}

	while (!myans.empty())
	{
		cout << myans.top() + 1 << " ";
		myans.pop();
	}
	cout << endl;


	/*
	vector<long long> myans;
	long long curpos = ansindex;
	while (curpos >= 0)
	{
		myans.push_back(curpos+1);
		long long j = lower_bound(dp.begin(), dp.begin() + curpos, dp[curpos]-1) - dp.begin();
		curpos = j;
	}

	cout << ans << endl;
	for (long long i = (long long)(myans.size()) - 1; i >= 0; --i)
	{
		cout << myans[i] << " ";
	}
	cout << endl;
	*/

	/*
	long long cur = 1;
	for (long long i = 0; i < dp.size(); ++i)
	{
		if (dp[i] == cur)
		{
			cout << i + 1 << " ";
			cur += 1;
		}
	}
	cout << endl;
	*/
	
	return 0;
}
