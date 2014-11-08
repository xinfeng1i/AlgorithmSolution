#include <iostream>
#include <string>
using namespace std;

int Sqrt(int x)
{
	const double EPS = 1e-7;
	double a = x;
	double guess = 1.0;
	double left = a / guess;
	double right = guess;
	while (left - right > EPS || left - right < -EPS)
	{
		guess = (left + right) / 2.0;
		left = a / guess;
		right = guess;
	}
	int ans = (int)right;
	return ans;
}

int main()
{
	int a;
	cin >> a;
	cout << Sqrt(a) << endl;
	return 0;
}
