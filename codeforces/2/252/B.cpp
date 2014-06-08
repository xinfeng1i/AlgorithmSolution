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
	//table.reserve(n);
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		table[a] += b;
	}

	vector<int> fruit;
	fruit.reserve(n);
	for (auto it = table.begin(); it != table.end(); ++it)
	{
		fruit.push_back(it->second);
	}

	long long ans = min(fruit[0], v);
	fruit[0] -= min(fruit[0], v);

	
	for (int i = 1; i <= fruit.size() ; ++i)
	{
		int cur = v;			
		int getPrev = min(fruit[i-1], cur);
		ans += getPrev;
		fruit[i-1] -= getPrev;
		cur -= getPrev;

		if (i < fruit.size())
		{
			int getCur = min(fruit[i], cur);
			ans += getCur;
			fruit[i] -= getCur;
			cur -= getCur;
		}
	}

	cout << ans << endl;
	return 0;
}
