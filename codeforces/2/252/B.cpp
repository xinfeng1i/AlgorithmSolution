#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n, v;
	cin >> n >> v;

	map<int, int> table;
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		table[a] += b;
	}

	long long ans = 0;
	for (int day = 1; day <= 3000 + 5; ++day)
	{
		int todayCapacity = v;
		if (table.count(day-1) != 0)
		{
			int getPrev = min(table[day-1], todayCapacity);
			table[day-1] -= getPrev;
			todayCapacity -= getPrev;
			ans += getPrev;
		}
		
		if (table.count(day) != 0)
		{
			int getCur = min(table[day], todayCapacity);
			table[day] -= getCur;
			todayCapacity -= getCur;
			ans += getCur;
		}
	}

	cout << ans << endl;
	return 0;
}
/* the fruit can be picked on days that is dicreted
 * for example
 * 1, 10, 20th day
 * the on 11th day only 10 can be picked
 * but on 12th day not any apples can be picked
 */
/*
 * Implementation:
 * When you need a map structure, consider the big array in replace
 */
