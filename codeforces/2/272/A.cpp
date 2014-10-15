#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int x = n / 2; x >= 0; --x)
	{
		int y = n - 2 * x;
		if (x >= 0 && y >= 0 && (x+y) % m == 0)
		{
			cout << x+y << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

