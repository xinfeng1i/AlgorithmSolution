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

string longestCommonPrefix(vector<string> &strs) 
{
	if (strs.size() <= 0) return "";
	if (strs.size() == 1) return strs[0];

	int n = strs.size();
	bool flag = true;

	int minlen = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		minlen = min(minlen, int(strs[i].size()));
	}

	int pos = 0;
	while (pos < minlen)
	{
		flag = true;
		for (int i = 1; i < n; ++i)
		{
			if (strs[i][pos] != strs[0][pos])
			{
				flag = false;
				break;
			}
		}

		if (flag == false) break;

		pos++;
	}

	return strs[0].substr(0, pos);
}

int main()
{
	string a = "a";
	string b = "a";
	vector<string> v;
	v.push_back(a);
	v.push_back(b);

	cout << longestCommonPrefix(v) << endl;
	return 0;
}