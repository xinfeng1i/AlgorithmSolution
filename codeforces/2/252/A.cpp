#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	set<int> ans;

	int n; long v;
	cin >> n >> v;
	for (int i = 1; i <= n; ++i)
	{
		int k; long cur_item;
		cin >> k;
		for (int j = 0;  j < k; ++j)
		{
			cin >> cur_item;
			if (cur_item < v)
			{
				ans.insert(i);
			}
		}
	}

	if (ans.size() == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << ans.size() << endl;
		for (set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			cout << " " << *it;
		}
		cout << endl;
	}

	return 0;
}
