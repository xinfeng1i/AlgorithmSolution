#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;

	vector<int> v(n+1, 0);
	for (int i = 0; i < n; ++i)
	{
		v[i] = s[i] - '0';
	}

	vector<int> v2(v);
	v2[0] += 1;
	for (int i = 0; i < n; ++i)
	{
		if (v2[i] == 2)
		{
			v2[i+1] += 1;
			v2[i] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] != v2[i])
		{
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}

