#include <iostream>
#include <string>
using namespace std;

int main()
{
	int left = -2*1E9;
	int right = 2*1E9;

	string sgn;
	int x;
	char answer;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> sgn >> x >> answer;
		if (sgn == ">")
		{
			answer == 'Y' ? left = max(x+1, left) : right = min(right, x);
		}
		else if (sgn == "<")
		{
			answer == 'Y' ? right = min(right, x-1) : left = max(left, x);
		}
		else if (sgn == ">=")
		{
			answer == 'Y' ? left = max(left, x) : right = min(right, x-1);
		}
		else
		{
			answer == 'Y' ? right = min(right, x) : left = max(left, x+1);
		}

	}

	if (left <= right)
	{
		cout << left << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}

	return 0;
}
