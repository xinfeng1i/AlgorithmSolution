#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;


int titleToNumber(string s) 
{
	long long ans = 0;

	long long weight = 1;
	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		ans += ((*it) - 'A' + 1) * weight;
		weight *= 26;
	}

	if (ans > INT_MAX || ans < INT_MIN) return -1;

	return (int)ans;
}

int main()
{
	string s;
	while (cin >> s)
	{
		cout << titleToNumber(s) << endl;
	}
	return 0;
}