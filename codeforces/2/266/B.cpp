#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;

	long long t1 = 0;
	long long t2 = 0;
	while (a * b < 6 * n)
	{
		t1 = (a + 1) * b;
		t2 = a * (b + 1);
		if (t1 <= t2) a++;
		else b++;
	}

	cout << a * b << endl;
	cout << a << " " << b << endl;
	return 0;
}
