#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long r, g, b;
	cin >> r >> g >> b;

	vector<long long> v;
	v.push_back(r);
	v.push_back(g);
	v.push_back(b);
	sort(v.begin(), v.end());
	long kmin = v[0];
	long long cnt = kmin;
	long long x = v[1] - kmin;
	long long y = v[2] - kmin;
	while (x >= 0 && y >= 0)
	{
		if (x <= y)
		{
			y -= 2;
			x -= 1;
			if (x < 0 || y < 0) break;
			cnt++;
		}
		else
		{
			swap(x, y);
		}
	}
	cout << cnt << endl;
	return 0;
}
