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

map<string, set<int> > table;
int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);

	int courseID, studentNum; 
	string name;
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d", &courseID, &studentNum);
		for (int j = 0; j < studentNum; ++j)
		{
			cin >> name;
			table[name].insert(courseID);
		}
	}

	string queryName;
	for (int i = 0; i < n; ++i)
	{
		cin >> queryName;
		printf("%s %d", queryName.c_str(), table[queryName].size());
		for (auto it = table[queryName].begin(); it != table[queryName].end(); ++it)
		{
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
