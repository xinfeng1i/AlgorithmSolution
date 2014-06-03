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

int xiaochu(vector<int> &v)
{
	//for (int i = 0; i < v.size(); ++i) cout << " " << v[i];
	//cout << endl;

	int n = v.size();
	bool flag = false;
	int i;
	for (i = 0; i + 2 < n; ++i)
	{
		if (v[i] == v[i+1] && v[i+1] == v[i+2])
		{
			flag = true;
			break;
		}
	}

	if (!flag) 
	{
		return 0;
	}
	else
	{
		int j = i;
		while (j < n && v[j] == v[i]) j++;
		vector<int> vv; vv.reserve(n);
		for (int ii = 0; ii < i; ++ii) vv.push_back(v[ii]);
		for (int jj = j; jj < n; ++jj) vv.push_back(v[jj]);
		return max(j - i + xiaochu(vv), 0);
	}

}

int main()
{
	int n, k, x;
	//scanf("%d %d %d\n", &n, &k, &x);
	cin >> n >> k >> x;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) 
		//scanf("%d", &v[i]);
		cin >> v[i];

	int ans = -1;
	for (int i = 0; i <= n; ++i)
	{
		vector<int> vv(v.begin(), v.end());
		vv.insert(vv.begin() + i, x);
		int curCnt = xiaochu(vv);
		ans = max(ans, curCnt);
	}
	ans = max(ans-1, 0);

	cout << ans << endl;

	return 0;
}
