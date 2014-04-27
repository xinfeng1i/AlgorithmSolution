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

int HashByName(char s[])
{
	return ((s[0]-'A') * 26 * 26 + (s[1]-'A') * 26 + (s[2]-'A')) * 10 + (s[3] -'0');
}

map<int, vector<int> > table;
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
			table[HashByName(name)].push_back(courseID);
		}
	}

	char queryName[10];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", queryName);
		printf("%s %d", queryName, table[HashByName(queryName)].size());
		vector<int> courseList = table[HashByName(queryName)];
		sort(courseList.begin(), courseList.end());
		for (auto it = courseList.begin(); it != courseList.end(); ++it)
		{
			printf(" %d", *it);
		}
		printf("\n");
	}
	return 0;
}
