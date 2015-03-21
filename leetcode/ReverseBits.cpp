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
#include <bitset>
#include <cstdio>
#include <cstdlib>
using namespace std;

unsigned int reverseBits(unsigned int n)
{
	unsigned int nBits = sizeof(n) * 8;
	unsigned int ans = 0U;
	unsigned int tmp = 0U;
	for (int i = 0; i < nBits; ++i)
	{
		tmp = n & (1 << i);
		if (tmp)
		{
			ans ^= (1 << nBits - 1 - i);
		}

	}
	return ans;	
}

int main()
{
	unsigned int n;
	cin >> n;
	cout << reverseBits(n) << endl;
	return 0;
}