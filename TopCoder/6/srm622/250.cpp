#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// AC code: 234pts
class FibonacciDiv2
{
public:
	int find(int N)
	{
		int a = 0;
		int b = 1;
		while (a + b < N)
		{
			int tmp = a + b;
			a = b;
			b = tmp;
		}

		return min(a + b - N, N - b);
	}
};