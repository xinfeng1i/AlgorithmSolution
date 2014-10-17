#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	long long kmax = (n-m+1)*(n-m)/2;

	long long kmin = 0;
	if (n % m == 0)
	{
		long long avg = n / m;
		kmin = m*avg*(avg-1)/2;
	}
	else
	{
		long long avg = n / m;
		long long r = n % m;
		kmin = (avg+1)*avg/2 * r + avg*(avg-1)/2 * (m-r);
	}

	cout << kmin << " " <<  kmax << endl;
	return 0;
}
