#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	long long n1, n2;
	cin >> n1 >> n2;
	vector<long long> v1(n1, 0);
	vector<long long> v2(n2, 0);
	for (long long i = 0; i < n1; ++i)
	{
		cin >> v1[i];
	}
	for (long long i = 0; i < n2; ++i)
	{
		cin >> v2[i];
	}

	long long cnt = 0;
	for (long long i = 0; i <= n1 - n2; ++i)
	{
		long long d = v1[i] - v2[0];
		bool flag = true;
		for (long long j = 1; j < n2; ++j)
		{
			if (v1[i+j] - v2[j] != d)
			{
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
	}

	cout << cnt << endl;
	return 0;
}
