#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int step = 1;
	int curx = 1;
	int cury = 1;
	for (int i = 0; i < k - 1; ++i)
	{
		cout << 2;
		for (int j = 0; j < 2; ++j)
		{
			cout << " " << curx << " " << cury;
			cury += step;
			if (cury > m)
			{
				cury = m;
				curx++;
				step = -step;
			}
			else if (cury < 1)
			{
				cury = 1;
				curx++;
				step = -step;
			}
		}
		cout << endl;
	}

	int remain = m * n - 2 * (k - 1);
	cout << remain;
	for (int j = 0; j < remain; ++j)
	{
		cout << " " << curx << " " << cury;
		cury += step;
		if (cury > m)
		{
			cury = m;
			curx++;
			step = -step;
		}
		else if (cury < 1)
		{
			cury = 1;
			curx++;
			step = -step;
		}
	}
	cout << endl;

	return 0;

}
