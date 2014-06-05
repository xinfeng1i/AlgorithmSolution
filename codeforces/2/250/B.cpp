#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x = 0;
	cin >> x;
	
	int ans = x - ((x >> 2) << 2);
	cout << ans << endl;
	return 0;
}
