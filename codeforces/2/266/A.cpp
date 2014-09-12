#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (b >= a * m)
	{
		int ans = a * n;
		cout << ans << endl;
	}
	else
	{
		int ans = 0;
		int k = n / m;
		ans += k * b;
		
		int r = n % m;
		int a1 = r * a;
		int a2 = b;
		ans += min(a1, a2);
		cout << ans << endl;
	}
	return 0;
}
