#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n = 0;
	scanf("%d\n", &n);

	vector<string> v(n);
	size_t minLen = 1000000;
	for (int i = 0; i < n; ++i)
	{
		getline(cin, v[i]);
		minLen = min(minLen, v[i].length());
	}

	string ans;
	int ansLen = 0;
	for (int k = 1; k <= minLen; ++k)
	{
		string suffix = v[0].substr(int(v[0].size())-k);
		bool iscommon = true;
		for (int i = 1; i < n; ++i)
		{
			if (v[i].substr(int(v[i].size())-k) != suffix)
			{
				iscommon = false;
				break;
			}
		}

		if (iscommon)
		{
			ans = suffix;
			ansLen = k;
		}
		else
		{
			break;
		}
	}

	if (ans == "") cout << "nai" << endl;
	else cout << ans << endl;

	return 0;
}
