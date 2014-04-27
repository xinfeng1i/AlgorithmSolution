#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> gids;

int HashByName(char s[])
{
	return ((s[0]-'A') * 26 * 26 + (s[1]-'A') * 26 + (s[2]-'A')) * 10 + (s[3]-'0');
}

int bsearch(int gid)
{
	int l = 0;
	int r = gids.size() - 1;
	int mid = (l + r) / 2;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (gid < gids[mid]) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);

	int courseID, studentNum; 
	char name[10];
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d", &courseID, &studentNum);
		for (int j = 0; j < studentNum; ++j)
		{
			scanf("%s", name);
			int gid = HashByName(name) * 2500 + courseID - 1;
			gids.push_back(gid);
		}
	}

	sort(gids.begin(), gids.end());

	char queryName[10];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", queryName);
		int gg = HashByName(queryName) * 2500 - 1;
		int low = bsearch(gg);
		int gg2 = HashByName(queryName) * 2500 + 2499;
		int high = bsearch(gg2);

		printf("%s %d", queryName, high - low);
		for (int i = low + 1; i <= high; ++i)
		{
			printf(" %d", gids[i] % 2500 + 1);
		}
		printf("\n");
	}
	return 0;
}
