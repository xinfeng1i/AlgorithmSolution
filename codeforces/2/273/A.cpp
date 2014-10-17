#include <iostream>
#include <string>
using namespace std;

int main()
{
	int c1, c2, c3, c4, c5;
	int s = 0;
	cin >> c1 >> c2 >> c3 >> c4 >> c5;
	s = c1 + c2 + c3 + c4 + c5;
	if (s <= 0 || s % 5 != 0) cout << -1 << endl;
	else cout << s / 5 << endl;
	return 0;
}
