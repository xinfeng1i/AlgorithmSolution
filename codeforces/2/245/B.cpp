#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> xiaochu(vector<int>& v, bool &flag)
{
	int n = v.size();
	for (int i = 0; i <= n - 3; ++i)
	{
		if (v[i] == v[i+1] && v[i+1] == v[i+2])
			flag = true;
	}

	int maxcnt = 0;
	int maxindex = -1;
	for (int i = 0; i < n; )
	{
		int j = i;
		int cnt = 1;
		while (j < n && v[j+1] == v[j])
		{
			cnt++;
			j++;
		}
		if (cnt > maxcnt)
		{
			maxcnt = cnt;
			maxindex = i;
		}

		i = j;
	}

	vector<int> ans;
	for (int i = 0; i < maxindex; ++i)
	{
		ans.push_back(v[i]);
	}
	for (int i = maxindex; i < n; ++i)
	{
		ans.push_back(v[i]);
	}

	return ans;
}

int main()
{
	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		vector<int> vv(v.begin(), v.end());
		vv.insert(v.begin() + i, x);
		bool possible = false;
		vector<int> xiao = xiaochu(vv, possible);
		if (!possible)
		{
			continue;
		}
		while (possible)
		{
			vv = xiao;
			xiao = xiaochu(vv, possible);
		}
		ans = max(ans, n - int(vv.size()));

	}

	cout << ans << endl;

	return 0;
}
