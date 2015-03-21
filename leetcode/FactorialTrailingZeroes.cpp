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


int trailingZeroes(int n)
{
	int ans = 0;

	while (n >= 5)
	{
		ans += int(n / 5);
		n /= 5;
	}
	return ans;
}

#if 0
int main()
{
	cout << trailingZeroes(2015) << endl;
	return 0;
}
#endif //0