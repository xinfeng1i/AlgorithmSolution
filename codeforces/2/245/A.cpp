#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	map<int, int> table;
	vector<int> v(n);
	for (int i = 0;i < n; ++i)
	{
		scanf("%d", &v[i]);
		table[v[i]] = 0;
	}

	map<int, int>::iterator it;
	int cnt = 0;
	for (it = table.begin(); it != table.end(); ++it)
	{
		table[it->first] = cnt++;
	}

	int left, right;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &left, &right);
	}

	bool isFirst = true;
	for (int i = 0; i < n; ++i)
	{
		int x = v[i];
		if (isFirst) {cout << table[x] % 2; isFirst = false;}
		else cout << " " << table[x] % 2;
	}
	cout << endl;

	return 0;
}
