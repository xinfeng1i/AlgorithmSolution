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

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v(n);
	for (int i = 0;i < n; ++i)
	{
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());
	vector<int> flag(n, -1);

	int left, right;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &left, &right);
		int cnt = 0;
		int n0 = 0; int n1 = 0;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] >= left && v[i] <= right)
			{
				if (cnt % 2 == 0 && flag[i] == -1)
				{
					flag[i] = 0;	
					cnt++;
					n0++;
				}
				else if (cnt % 2 == 1 && flag[i] == -1)
				{
					flag[i] = 1;
					cnt++;
					n1++;
				}
			}
		}

		if (abs(n0 - n1) > 1)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	bool isFirst = true;
	for (int i = 0; i < n; ++i)
	{
		if (isFirst) {printf("%d", flag[i]); isFirst = false;}
		else { printf(" %d", flag[i]);}
	}
	cout << endl;	
	return 0;
}
