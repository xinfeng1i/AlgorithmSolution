#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	for (int i = 1; i < n; ++i)
	{
		v[i] = v[i-1] + v[i];
	}

	//copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
	
	int m;
	cin >> m;
	int q;
	for (int k = 0; k < m; ++k)
	{
		cin >> q;
		for (int i = 0; i < n; ++i)
		{
			if (q <= v[i])
			{
				cout << i+1 << endl;
				break;
			}
		}
	}
	
	return 0;
}
