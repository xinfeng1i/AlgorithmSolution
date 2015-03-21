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

int singleNumber(int A[], int n)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans ^= A[i];
	}
	return ans;
}