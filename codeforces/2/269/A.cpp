#include <iostream>
#include <vector>
using namespace std;

int cnt[10];

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		cnt[i] = 0;
	}

	int tmp;
	for (int i = 0; i < 6; ++i)
	{
		cin >> tmp;
		cnt[tmp]++;
	}

	int index = -1;
	bool flag = true;
	for (int i = 0; i < 10; ++i)
	{
		if (cnt[i] >= 4)
		{
			index = i;
			break;
		}
	}

	if (index == -1) 
	{
		cout << "Alien" << endl;
		return 0;
	}

	cnt[index] -= 4;
	int a = -1; int b = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (cnt[i] != 0)
		{
			a = i;
			cnt[i] -= 1;
			break;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if (cnt[i] != 0)
		{
			b = i;
			cnt[i] -= 1;
			break;
		}
	}

	if (a == b)
	{
		cout << "Elephant" << endl;
	}
	else
	{
		cout << "Bear" << endl;
	}

	return 0;
}
