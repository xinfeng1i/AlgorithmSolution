#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int divide(int m, int n)
{
	// Exception: n == 0, m == INT_MiN && n == -1
	if (n == 0 || (m == INT_MIN && n == -1)) return INT_MAX;

	int sign = ((m < 0) ^ (n < 0) ? -1 : 1);
	long long mm = abs((long long)m);
	long long nn = abs((long long)n);

	long long ans = 0;
	while (mm >= nn) {
		long long temp = nn;
		long long multiple = 1;
		while (mm - temp >= temp) {
			temp += temp;
			multiple += multiple;
		}
		mm -= temp;
		ans += multiple;
	}
	return sign == 1 ? ans : -ans;
}

int main()
{
	int m, n;
	while (cin >> m >> n) {
		cout << m << " " << n << endl;
		int ans = divide(m, n);
		cout << m << "/" << n << "=" << ans << endl;
	}
	return 0;
}
