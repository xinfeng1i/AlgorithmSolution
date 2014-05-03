#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);

	char id[20]; int flightLength;
	unordered_map<string, int> table;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d", id, &flightLength);
		string mykey(id);
		table[mykey] += max(flightLength, k);
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", id);
		string query(id);
		if (table.count(query) == 0) printf("No Info\n");
		else printf("%d\n", table[query]);
	}

	return 0;
}
