#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numberOfDifferentBits(int a, int b)
{
	int tmp = a ^ b;
	int cnt = 0;
	while (tmp != 0)
	{
		cnt += tmp & 1;
		tmp = (tmp >> 1);
	}

	return cnt;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v(m+1, 0);
	for (int i = 0; i < m+1; ++i)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		int tmp = numberOfDifferentBits(v[i], v[m]);
		if (tmp <= k)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
