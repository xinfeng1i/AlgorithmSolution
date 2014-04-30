#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i];
    }

    long tmp = 0;
    for (int k = 1; k <= n; ++k)
    {
    	for (int i = 1; i <= n; ++i)
	{
		tmp ^= i % k;
	}
    }

    for (int i = 0; i < n; ++i)
    {
    	tmp ^= v[i];
    }
    cout << tmp << endl;
    return 0;
}
