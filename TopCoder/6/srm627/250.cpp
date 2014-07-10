#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;


const int MAX_LENGTH = 1005;
int howManySquares(vector<int> sticks)
{
	int n = sticks.size();
	vector<int> cnt(MAX_LENGTH, 0);
	for (int i = 0; i < n; ++i)
	{
		int len = sticks[i];
		cnt[len]++;
	}

	int ans = 0;
	for (int i = 0; i < MAX_LENGTH; ++i)
	{
		ans += cnt[i] / 4;
	}

	return ans;
}
