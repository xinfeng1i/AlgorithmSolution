#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

bool isPrime(long long n)
{
	assert(n >= 0);
	// NOTE: 1 is NOT prime
	if (n <= 1) return false;
	long long mid = (long long)sqrt(double(n));
	for (long long i = 2; i <= mid; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}



int main()
{
	int msize; int n;
	cin >> msize >> n;
	int Tsize;
	if (isPrime(msize))
	{
		Tsize = msize;
	}
	else
	{
		do{
			msize++;
		}while(!isPrime(msize));
		Tsize = msize;
	}
	assert(isPrime(Tsize));
	
	vector<int> HTable(Tsize, -1);
	vector<int> ans(n, -1);

	long long tmp; int index;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		for (int k = 0; k < Tsize; ++k)
		{
			// NOTE: k = 0,1,2,..., Tsize - 1;
			index = (tmp % Tsize + k * k) % Tsize;
			if (HTable[index] == -1)
			{
				HTable[index] = tmp;
				ans[i] = index;
				break;
			}
		}
	
	}

	bool isFirst = true;
	for (int i = 0; i < n; ++i)
	{
		if (isFirst) isFirst = false;
		else cout << " ";

		if (ans[i] != -1) cout << ans[i];
		else cout << "-";
	}
	cout << endl;

	return 0;
}
