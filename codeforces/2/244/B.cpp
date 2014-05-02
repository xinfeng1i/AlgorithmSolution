#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, t, c;
	scanf("%d %d %d", &n, &t, &c);

	vector<int> v(n, 0);
	vector<int> badIndex;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
		if (v[i] > t) 
		{
			badIndex.push_back(i);
		}
	}
	
	if (badIndex.size() == 0)
	{
		cout << n - c + 1 << endl;
	}
	else if (badIndex.size() == 1)
	{
		int ans = 0;
		int index = badIndex[0];
		ans += (index >= c ? (index - c + 1) : 0);
		ans += (n - index - 1 >= c ? (n - index - c):0);
		cout << ans << endl;
	}
	else
	{
		int ans = 0;
		for (int i = 0; i + 1 < badIndex.size(); ++i)
		{
			int index1 = badIndex[i];
			int index2 = badIndex[i+1];
			ans += (index2 - index1 - 1 >= c ? (index2 - index1 - c):0);
		}

		if (badIndex[0] != 0)
		{
			int index = badIndex[0];
			ans += (index >= c ? (index + 1 - c):0);
		}

		int m = badIndex.size();
		if (badIndex[m-1] != n - 1)
		{
			int index = badIndex[m-1];
			ans += (n - 1 - index >= c ? (n - index - c):0);
		}
		cout << ans << endl;
	}
	
	return 0;
}
