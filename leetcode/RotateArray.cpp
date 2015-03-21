#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}


void rotate(int nums[], int n, int k) 
{
	k = k % n;

	int looptime = gcd(n, k);
	for (int i = n - 1; i >= n - looptime; --i)
	{
		int curPos = i;
		int tmp = nums[curPos];
		int rotatetime = n / looptime;
		for (int j = 0; j < rotatetime - 1; ++j)
		{
			int prePos = (curPos - k + n) % n;
			nums[curPos] = nums[prePos];
			curPos = prePos;
		}
		nums[curPos] = tmp;
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int b[] = {0, 1, 2, 3, 4, 5};
	int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	rotate(a, 7, 3);
	rotate(b, 6, 4);
	rotate(c, 9, 6);

	for (int i = 0; i < 7; ++i)
	{
		cout << " " << a[i];
	}
	cout << endl;

	for (int i = 0; i < 6; ++i)
	{
		cout << " " << b[i];
	}
	cout << endl;

	for (int i = 0; i < 9; ++i)
	{
		cout << " " << c[i];
	}
	cout << endl;
	return 0;
}