#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long n, d;

int main()
{
	cin >> n >> d;

	vector<long long> v(n);
	vector<long long> dp(n+1, 1);

	for (long long i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	
	for (long long i = 1; i < n; ++i)
	{
		for (long long j = 0; j < i; ++j)
		{
			if (abs(v[j] - v[i]) >= d)
			{
				dp[i] = max(dp[i], dp[j]+1);
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

	//cout << ansindex << endl;
	/*
	vector<long long> myans;
	long long curpos = ansindex;
	while (curpos >= 0)
	{
		myans.push_back(curpos+1);
		long long j = curpos - 1;
		for (j = curpos - 1; j >= 0; --j)
		{
			if (dp[j] == dp[curpos] - 1)
			{
				break;
			}
		}
		curpos = j;
	}
	*/

	cout << ans << endl;
	/*
	for (long long i = (long long)myans.size() - 1; i >= 0; --i)
	{
		cout << myans[i] << " ";
	}
	cout << endl;
	*/

	long long cur = 1;
	for (long long i = 0; i < dp.size(); ++i)
	{
		if (dp[i] == cur)
		{
			cout << i + 1 << endl;
			cur += 1;
		}
	}
	
	return 0;
}
