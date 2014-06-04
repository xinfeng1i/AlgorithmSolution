#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	sort(v.begin(), v.end());

	long long sum = 0;
	int speed = x;
	for (int i = 0, speed = x; i < n; ++i, speed--)
	{
		sum += (long long)(v[i]) * max(speed, 1);
	}
	
	cout << sum << endl;
	return 0;
}
