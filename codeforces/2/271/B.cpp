#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int bsearch(const vector<int>& v, int q)
{
	int n = v.size();
	int left = 0;
	int right = n - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (q == v[mid])
		{
			return mid;
		}
		else if (q > v[mid])
		{
			left = mid + 1;
		}
		else
		{
			if (mid - 1 < 0) return mid;
			else if (q > v[mid-1]) return mid;
			right = mid - 1;
		}
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 1; i < n; ++i)
	{
		v[i] = v[i-1] + v[i];
	}

	//copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	
	int m;
	cin >> m;
	int q;
	for (int k = 0; k < m; ++k)
	{
		cin >> q;
		//int ans = bsearch(v, q);
		int ans = lower_bound(v.begin(), v.end(), q) - v.begin();
		cout << ans + 1 << endl;
	}
	
	return 0;
}
