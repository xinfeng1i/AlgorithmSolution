#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
using namespace std;

int reverse(int x)
{
	long ans = 0;
	while(x != 0)
	{
		ans = 10 * ans + (x % 10);
		x /= 10;
	}

	if (x < 0) ans = -ans;

	// NOTE: reverse number may be overflow
	if (ans > INT_MAX || ans < INT_MIN) ans = 0;

	return (int)ans;
}

#if 0
int main()
{
	int x;
	cin >> x;
	cout << reverse(x) << endl;
	return 0;
}
#endif //0