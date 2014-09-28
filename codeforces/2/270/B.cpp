#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	deque<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	int cnt = 0;
	while (!v.empty())
	{
		// after this turn, stil have some people
		if (v.size() > k)
		{
			int curHigh = v.front();
			for (int j = 0; j < k; ++j) v.pop_front();
			cnt += (curHigh - 1) * 2;
		}
		// this is the last turn
		else
		{
			int curHigh = v.front();
			while (!v.empty()) v.pop_front();
			cnt += (curHigh - 1) * 2;
		}
	}
	cout << cnt << endl;
	return 0;
}
