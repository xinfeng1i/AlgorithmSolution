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
	int n, d;
	cin >> n >> d;

	int t, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		sum += t;
	}
	sum += (n-1) * 10;
	
	int remain = d - sum;
	if (remain >= 0)
		cout << remain / 5 + (n-1)*2 << endl;
	else
		cout << -1 << endl;

	return 0;
}
