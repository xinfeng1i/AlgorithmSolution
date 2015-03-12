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

int hammingWeight(int n)
{
	int ans = 0;
	while (n != 0)
	{
		ans++;
		n = n & (n - 1);
	}
	return ans;
}

#if 0
int main()
{
	int x;
	cin >> x;
	cout << hammingWeight(x) << endl;
	return 0;
}
#endif //0