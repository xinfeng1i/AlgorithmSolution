#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(4);
	v[0] = n / 1000;
	v[1] = (n % 1000) / 100;
	v[2] = (n % 100) / 10;
	v[3] = n % 10;

	if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3])
	{
		printf("%04d - %04d = 0000\n", n, n);
		return 0;
	}

	do
	{
		sort(v.begin(), v.end(), greater<int>());
		int a = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
		sort(v.begin(), v.end(), less<int>());
		int b = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
		n = a - b;
		printf("%04d - %04d = %04d\n", a, b, n);
		v[0] = n / 1000;
		v[1] = (n % 1000) / 100;
		v[2] = (n % 100) / 10;
		v[3] = n % 10;
	}while (n != 6174);
	// if use while loop, the sample 6174 will not print anything

	return 0;
}
