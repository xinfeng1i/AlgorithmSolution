#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool CanSumX(int x, vector<int> S)
{
	if (x < 0) return false;
	for (int i = 0; i < S.size(); ++i)
	{
		if (x == S[i]) return true;
	}
	if (S.size() == 1)
	{
		return x == S[0];
	}

	//cout << "x=" << x << endl;
	int n = S.size();
	bool ans = false;
	for (int i = 0; i < n; ++i)
	{
		int ai = S[i];
		vector<int> tmp(S);
		tmp.erase(tmp.begin() + i);
		if (CanSumX(x - ai, tmp))
		{
			return true;
		}
	}
	return false;
}


int MinNumber(vector<int> S)
{
	int n = S.size();
	int max = accumulate(S.begin(), S.end(), 0);
	//cout << "max=" << max << endl;
	for (int i = 1; i <= max; ++i)
	{
		int x = i;
		if (!CanSumX(x, S))
		{
			return x;
		}
	}

	return max + 1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int ans = MinNumber(v);
	cout << ans << endl;
	return 0;
}
