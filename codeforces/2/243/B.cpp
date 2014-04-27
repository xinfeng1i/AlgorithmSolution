#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector<vector<int> > VV;

bool isEqual(vector<int> &a, vector<int>& b)
{
	int n = a.size();
	for (int i = 0; i < n; ++i)
	{
		if (a[i] != b[i]) return false;
	}

	return true;
}

int minRow(VV &a)
{
	int n = a.size();
	int m = a[0].size();
	if (n % 2 == 1)
		return n;
	
	bool flag = true;;
	for (int i = 0, j = n - 1; i < n/2; ++i, --j)
	{
		if (!isEqual(a[i], a[j]))
		{
			flag = false;
			break;
		}
	}

	if (!flag)
		return n;
	else
	{
		VV tmp(n/2, vector<int>(m, 0));
		for (int i = 0; i < n/2; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				tmp[i][j] = a[i][j];
			}
		}

		return minRow(tmp);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	VV a(n, vector<int>(m, 0));
	for (int i  = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}

	int ans = minRow(a);
	printf("%d\n", ans);
	return 0;
}
