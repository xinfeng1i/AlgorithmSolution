#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(long n)
{
	long mid = (long)sqrt((double)n);
	for (long i = 2; i <= mid; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	long n;
	cin >> n;
	long a, b;
	for (a = 4; a <= n; ++a)
	{
		b = n - a;
		if (!isPrime(a) && !isPrime(b)) break;
	}

	cout << a << " " << b << endl;
	return 0;
}
