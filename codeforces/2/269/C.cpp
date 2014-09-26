#include <iostream>
#include <vector>
#include <set>
using namespace std;

int BuildHouse(long long n, long long premax, long long curmax)
{
	// base case
	if (n == 0)
	{
		return 0;
	}
	if (n == 2 && curmax == 1)
	{
		return 1;
	}

	set<long long> s;
	if (curmax <= premax)
	{
		for (int i = curmax; i >= 1; --i)
		{
			long long cost = 3 * i - 1;
			long long h = BuildHouse(n - cost, i, i - 1);
			s.insert(h+1);
		}
	}
	return s.size();
}

int main()
{
	long long n = 0;
	cin >> n;
	long k = (n + 1) / 3;
	int ans = BuildHouse(n, k, k);
	cout << ans << endl;
	return 0;
}
