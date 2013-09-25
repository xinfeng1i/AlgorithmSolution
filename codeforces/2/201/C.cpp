#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Greatest Common Divisor between a and b
long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}


// return the greatest common divisor among all values in v
// Time complexity:
long long arrayGcd(vector<long long> v)
{
	long long result = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		result = gcd(result, v[i]);
	}

    return result;
}

int main()
{
	// read input
	int n = 0;
	cin >> n;
	vector<long long> v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}


	long long max_elem = *max_element(v.begin(), v.end());
	long long d = arrayGcd(v);

	long long remain_round = max_elem / d - v.size();
	if (remain_round % 2 == 1)
	{
		cout << "Alice" << endl;
	}
	else
	{
		cout << "Bob" << endl;
	}
	return 0;
}


// Summary:
// 1. calculate GCD use Euler Algorithm
// 2. calculate other GCD always depends on Euler's GCD Algorithm
// 3. figure out why we can achieve all the differece |x-y| in such
//    way, what's behind ? Number Theory ?
