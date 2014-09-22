#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int p, q;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> p >> q;
		if (q - p >= 2)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}
