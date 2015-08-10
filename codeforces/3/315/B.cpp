#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

#if 0
int main()
{
	int n;
	int val = 0;
	scanf("%d", &n);

	vector<int> v(n, 0);
	vector<int> used(n, 0);
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
		val = v[i];
		if (val >= 1 && val <= n && s.find(val) == s.end())
		{
			s.insert(val);
			used[i] = 1;
		}
	}

	set<int> tot;
	for (int i = 1; i <= n; ++i) tot.insert(i);

	size_t sz = tot.size() - s.size();
	vector<int> diff;
	set_difference(tot.begin(), tot.end(),
		s.begin(), s.end(), std::inserter(diff, diff.begin()));

	int idx = 0;
	for (int i = 0; i < n; ++i)
	{
		if (used[i]) continue;
		else v[i] = diff[idx++];
	}

	for (int i = 0; i < n; ++i)
	{
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	printf("\n");

	return 0;
}
#endif //0